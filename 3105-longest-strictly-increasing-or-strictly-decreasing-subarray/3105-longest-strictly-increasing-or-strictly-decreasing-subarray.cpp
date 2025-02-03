class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1,pre=nums[0],maxi=1,maxd=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>pre){inc++; maxi=max(inc,maxi); dec=1;}
            else if(nums[i]<pre){dec++; maxd=max(dec,maxd); inc=1;}
            else{ maxi=max(inc,maxi); maxd=max(dec,maxd); inc=1; dec=1;}
            pre=nums[i];
        }
    return max(maxi,maxd);}
};