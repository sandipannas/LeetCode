class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int left=0;

        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i]) && map[nums[i]]!=0) return true;
            if(i<k){ map[nums[i]]++; continue; }

            map[nums[i]]++;
            map[nums[left++]]--;
        }
        return false;
    }
};