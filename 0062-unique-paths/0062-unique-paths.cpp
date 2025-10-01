class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m,vector<int>(n));
       dp[m-1][n-1]=1;
       for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int down=i+1>=m?0:dp[i+1][j];
            int right=j+1>=n?0:dp[i][j+1];
            dp[i][j]+=down+right;
        }
       }      
       return dp[0][0];
    }
};