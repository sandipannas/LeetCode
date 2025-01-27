class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> gg;
        vector<int> ans;
        for(int i:nums)
        {
            if(!gg.count(i))
            {
                gg.insert(make_pair(i,1));
            }
            else{
                gg[i]++;
            }
        }
        for(auto& it:gg)
        {
            if(it.second>n/3)
            {
                ans.push_back(it.first);
            }
        }
    return ans;}
};