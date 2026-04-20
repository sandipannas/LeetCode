class Solution {
public:
    bool rec(vector<int>& nums,int i,int target,vector<vector<int>>& dp){
        if(target==0){return true;}
        if(i<0){return false;}

        if(dp[i][target]!=-1){ return dp[i][target]; }

        //take
        bool a=nums[i]>target? false : rec(nums,i-1,target-nums[i],dp);
        //not take
        bool b=rec(nums,i-1,target,dp);

        return dp[i][target]=a||b;
    }

    bool canPartition(vector<int>& nums) {
     int sum=0;
     for(int i:nums){ sum+=i; }
     if(sum%2==1){ return false; }
     
     //dp
     vector<vector<int>> dp(nums.size(),vector<int>((sum/2)+1,-1));
     return rec(nums,nums.size()-1,sum/2,dp);  
    }
};