class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dpDown(n,INT_MAX);
        vector<int> dpRight(m,INT_MAX);


        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
              int tem=grid[i][j]+(j==n-1 && i==m-1 ? 0 : min(dpDown[j],dpRight[i]));
              dpDown[j]=tem;
              dpRight[i]=tem;
            }
        }

        return dpDown[0];
    }
};