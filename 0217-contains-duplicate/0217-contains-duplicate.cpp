class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> gg;
        for(int i:nums)
        {
            if(gg.count(i))
            {
                return true;
            }
            gg.insert(i);
        }
        return false;
    }
};