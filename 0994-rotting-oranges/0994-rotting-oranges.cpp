class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        unordered_map<int,vector<int>> graph;
        unordered_map<int,int> lowest_value;
        vector<int> rot;
        int node=0;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]==0){ node++; continue; }
              if(grid[i][j]==2){ rot.push_back(node); }
              lowest_value[node]=INT_MAX;
              int u=0,l=0,r=0,d=0;
              if(i-1>=0 && grid[i-1][j]!=0) { graph[node].push_back(node-n); u=1;}
              if(i+1<m && grid[i+1][j]!=0) { graph[node].push_back(node+n); d=1;}
              if(j-1>=0 && grid[i][j-1]!=0) { graph[node].push_back(node-1); l=1;}
              if(j+1<n && grid[i][j+1]!=0) { graph[node].push_back(node+1); r=1;}
              node++;
              if(u==0 && d==0 && l==0 && r==0 && grid[i][j]==1){
                return -1;
              }
            }
        }
        if(lowest_value.size()==0){ return 0;}
        if(rot.size()==0){ return -1; }

        for(int i:rot){
            queue<int> kwi;
            unordered_set<int> visited;
            kwi.push(i);
            visited.insert(i);
            lowest_value[i]=0;
            while(!kwi.empty()){
                int gg=kwi.front();
                kwi.pop();
                for(int ii:graph[gg]){
                    if(visited.count(ii)){ continue; }
                    visited.insert(ii);
                    kwi.push(ii);
                    lowest_value[ii]=min(lowest_value[ii],lowest_value[gg]+1);
                }
            }
        }
        int ans=0;
        for(auto& i:lowest_value){
            //cout<<"node->"<<i.first<<" value->"<<i.second<<endl;
            ans=max(i.second,ans);
        }
        if(ans==INT_MAX){return -1;}
        return ans;
    }
};