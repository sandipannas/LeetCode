class Solution {
public:
    bool check(int index,long long curr,vector<int>& nums,vector<vector<int>>& dp){
        if(curr==0){ return true; }
        if(index>=nums.size()){ return false; }
        if(dp[index][curr]!=-1){ return dp[index][curr]; }
        //take
        bool take=curr<nums[index]?false:check(index+1,curr-nums[index],nums,dp);
        //not take
        bool nTake=check(index+1,curr,nums,dp);

        return dp[index][curr]= take || nTake;
    }

    bool canPartition(vector<int>& nums) {
       long long total=0;
       for(int i:nums){
        total+=(long long)i;
       }
       if(total%2==1){ return false; }
       else { 
        vector<vector<int>> dp(nums.size(),vector<int>((total/2)+1,-1));
        return check(0,total/2,nums,dp); } 
    }
};