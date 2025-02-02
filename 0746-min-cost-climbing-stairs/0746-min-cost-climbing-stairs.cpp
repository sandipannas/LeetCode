class Solution {
public:
    int ans(int n,vector<int>& cost,vector<int>& dp){
        if(n==0 || n==1){return cost[n];}
        if(n<0){return 0;}
        if(dp[n]!=-1){return dp[n];}
        return dp[n]=min(ans(n-1,cost,dp),ans(n-2,cost,dp))+cost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,-1);
        return ans(n,cost,dp);
    }
};
