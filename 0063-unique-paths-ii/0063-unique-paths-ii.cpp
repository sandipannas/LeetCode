class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        vector<long long> dpRight(m,0);
        vector<long long> dpDown(n,0);

        dpRight[m-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dpDown[j]=(grid[i][j]==1)?0:dpDown[j]+dpRight[i];
                dpRight[i]=(grid[i][j]==1)?0:dpDown[j];
            }
        }

        return dpDown[0];

    }
};