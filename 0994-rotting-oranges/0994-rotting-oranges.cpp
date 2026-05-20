class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> line;

        //inserting the rotten oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    line.push({i,j});
                }
            }
        }

        line.push({-1,-1});
        int count=0;

        while(line.size()!=1){
            pair<int,int> current=line.front();
            line.pop();

            int i=current.first;
            int j=current.second;

            if(i==-1){
                count++; 
                line.push({-1,-1}); 
                continue;
            }

            //up
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                line.push({i-1,j});
            }
            //down
            if(i+1<m && grid[i+1][j]==1){
                grid[i+1][j]=2;
                line.push({i+1,j});
            }
            //left
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                line.push({i,j-1});
            }
            //right
            if(j+1<n && grid[i][j+1]==1){
                grid[i][j+1]=2;
                line.push({i,j+1});
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ return -1;}
            }
        }
       
       return count;


    }
};