class Solution {
public:
    vector<int> dp=vector<int>(32,-1);
    int fib(int n) {
        if(n<=1) { return n; }
        if(dp[n]!=-1){ return dp[n]; }

        return dp[n]=fib(n-2)+fib(n-1);
    }
};