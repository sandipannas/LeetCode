class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);

        int dp1=nums[0];
        int dp2=max(nums[0],nums[1]);

        for(int i=2;i<nums.size()-1;i++){
            int tem = max(dp2,dp1+nums[i]);
            dp1=dp2;
            dp2=tem;
        }

        int dpp1=0;
        int dpp2=nums[1];

        for(int i=2;i<nums.size();i++){
            int tem = max(dpp2,dpp1+nums[i]);
            dpp1=dpp2;
            dpp2=tem;
        }

        return max(dpp2,dp2);
        
    }
    
};