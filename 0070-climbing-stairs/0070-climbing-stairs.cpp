class Solution {
public:
    
    //-----top down approach

    // int count_ways(int n,vector<int>& dp){
    //     if(n<=1) return dp[n]=1; 
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=count_ways(n-1,dp)+count_ways(n-2,dp);
    // }

    //----bottom-up----
    int count_ways(int n,vector<int>& dp){
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
    }

    int climbStairs(int n) {
     vector<int> dp(n+1,-1);
     return count_ways(n,dp);
    }
};