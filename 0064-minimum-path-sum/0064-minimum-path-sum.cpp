class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> down(n,INT_MAX);
        vector<int> right(m,INT_MAX);

        right[m-1]=0; // only one base case

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
              right[i]=min(right[i],down[j])+grid[i][j];
              down[j]=right[i];
            }
        }

        return down[0];
    }
};
