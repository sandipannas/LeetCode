class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<int> down(n,INT_MAX);
        vector<int> right(m,INT_MAX);

        right[m-1]=0;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
              int ans=min(right[i],down[j])+grid[i][j];
              right[i]=ans;
              down[j]=ans;
            }
        }

        return down[0];

        

    }
};