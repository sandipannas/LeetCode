class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        int dp1=nums[0];
        int dp2=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int tem = max(dp2,dp1+nums[i]);
            dp1=dp2;
            dp2=tem;
        }

        return dp2;
    }
};