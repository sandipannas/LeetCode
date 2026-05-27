class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& grid,int i,int j){
        for(int k=0;k<4;k++){
            int ai=dir[k].first+i;
            int aj=dir[k].second+j;
            
            if(ai>=0 && ai<grid.size() && aj>=0 && aj<grid[0].size() && grid[ai][aj]==1){
                grid[ai][aj]=2;
                dfs(grid,ai,aj);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            if(i==0 || i==m-1){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        grid[i][j]=2;
                        dfs(grid,i,j);
                    }
                }
            }
            else{
                //0
                if(grid[i][0]==1){
                    grid[i][0]=2;
                    dfs(grid,i,0);
                }

                //n-1
                if(grid[i][n-1]==1){
                    grid[i][n-1]=2;
                    dfs(grid,i,n-1);
                }
            }
        }

        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ count++; }
            }
        }

        return count;
    }
};