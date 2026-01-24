class Solution {
public:
    void travel(vector<vector<int>>& visited, vector<vector<char>>& grid,int i,int j){
        if( i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j] || grid[i][j]=='0'){return;}
        visited[i][j]=1;

        //up
        travel(visited,grid,i-1,j);
        //right
        travel(visited,grid,i,j+1);
        //left
        travel(visited,grid,i,j-1);
        //down
        travel(visited,grid,i+1,j);
        
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();

        vector<vector<int>> visited(m,vector(n,0));
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(!visited[i][j] && grid[i][j]=='1'){      
                count++;

                travel(visited,grid,i,j);
               }
            }
        }

        return count;
    }
};