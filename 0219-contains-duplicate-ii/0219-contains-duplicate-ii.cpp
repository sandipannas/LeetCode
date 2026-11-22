class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int left=0;

        for(int i=0;i<nums.size();i++){
            if(set.count(nums[i])) return true;
            if(i<k){ set.insert(nums[i]); continue; }

            set.insert(nums[i]);
            set.erase(nums[left++]);
        }
        return false;
    }
};