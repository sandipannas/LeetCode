class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();

        int count=0;
        
        vector<vector<int>> visited(m,vector<int>(n));
        queue<pair<int,int>> line;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    visited[i][j]=1;
                    line.push({i,j});
                }
            }
        }


        while(line.size()!=0){

            int till=line.size();

            while(till--){

            int i=line.front().first;
            int j=line.front().second;
            line.pop();

            //cout<<"node is "<<i<<" "<<j<<endl;

            mat[i][j]=count;

            //up
            if(i-1>=0 && !visited[i-1][j]){
                //cout<<"pushing up "<<i-1<<" "<<j<<endl;
                visited[i-1][j]=1;
                line.push({i-1,j});
            }
            //down
            if(i+1<m && !visited[i+1][j]){
                //cout<<"pushing down "<<i+1<<" "<<j<<endl;
                visited[i+1][j]=1;
                line.push({i+1,j});
            }
            //left
            if(j-1>=0 && !visited[i][j-1]){
                //cout<<"pushing left "<<i<<" "<<j-1<<endl;
                visited[i][j-1]=1;
                line.push({i,j-1});
            }
            //right
            if(j+1<n && !visited[i][j+1]){
                //cout<<"pushing right "<<i<<" "<<j+1<<endl;
                visited[i][j+1]=1;
                line.push({i,j+1});
            }
            }

            count++;
        }
        return mat;
    }
};