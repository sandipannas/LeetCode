class Solution {
public:
    int ans(int n,vector<int>& dp)
    {
        if(n==0){return 1;}
        if(n<0) {return 0;}
        
        if(dp[n]!=-1){return dp[n];}
        int a=ans(n-1,dp);
        int b=ans(n-2,dp);
        return dp[n]=a+b;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ans(n,dp);
        //return dp[n];
    }
};