class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> ans;
        for(int i:nums){
            if(set.count(i)){
                ans.push_back(i);
            }
            else{
                set.insert(i);
            }
        }
        return ans;
    }
};