class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        queue<int> line;

        int count = 0;

        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            visited[i]=1;
            line.push(i);
            count++;

            while(!line.empty()){
              int current = line.front();
              line.pop();

              for(int j=0;j<n;j++){
                if(!visited[j] && current!=j && isConnected[current][j]){
                    visited[j]=1;
                    line.push(j);
                }
              }
            }


        }

        return count;
    }
};