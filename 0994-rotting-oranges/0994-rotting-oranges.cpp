class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> line;
        vector<vector<int>> visited(m,vector(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    pair<int,int> tem={i,j};
                    line.push(tem);
                    visited[i][j]=1;
                }
            }
        }

        line.push({-1,-1});

        int count=0;
        
        while(line.size()>1){
            if(line.front().first==-1){
              count++;
              line.pop();
              line.push({-1,-1});
            }
            else{
                 int row=line.front().first;
                 int col=line.front().second;
                 line.pop();
                 
        

                 //up
                 if((row-1>=0 && grid[row-1][col]==1) && visited[row-1][col]==0){
                    visited[row-1][col]=1;
                    grid[row-1][col]=2;
                    line.push({row-1,col});
                 }
                 //right
                if(col+1<n && grid[row][col+1]==1 && visited[row][col+1]==0){
                    visited[row][col+1]=1;
                    grid[row][col+1]=2;
                    line.push({row,col+1});
                 }
                 //left
                if(col-1>=0 && grid[row][col-1]==1 && visited[row][col-1]==0){
                    visited[row][col-1]=1;
                    grid[row][col-1]=2;
                    line.push({row,col-1});
                 }
                 //down
                if(row+1<m && grid[row+1][col]==1 && visited[row+1][col]==0){
                    visited[row+1][col]=1;
                    grid[row+1][col]=2;
                    line.push({row+1,col});
                 }
            }

        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return count;


    }
};