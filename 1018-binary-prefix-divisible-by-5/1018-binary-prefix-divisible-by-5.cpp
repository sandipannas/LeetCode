class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int msb=0, n=nums.size();
        vector<bool> ans(n);
        for_each(nums.begin(), nums.end(), [&, i=-1](int x) mutable{
            ans[++i]=(msb=((msb<<1)+x)%5)==0;});
        return ans;
    }
};