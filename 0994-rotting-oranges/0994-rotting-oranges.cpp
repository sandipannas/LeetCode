class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        unordered_map<int,int> lowest_value;
        vector<int> rot;
        int node=0;

        for(auto& i:grid){
            for(int j:i){
              if(j==2){ rot.push_back(node); }
              if(j==1){ lowest_value[node]=INT_MAX; }
              node++;
            }
        }
        if(lowest_value.size()==0){
            return 0;
        }

        for(int i:rot){

            
            queue<int> kwi;  unordered_set<int> visited;
            
            kwi.push(i);
            visited.insert(i);
            lowest_value[i]=0;

            while(!kwi.empty()){

                int gg=kwi.front();  kwi.pop();
                int row=gg/n,col=gg%n;   
                
              if(row-1>=0 && grid[row-1][col]!=0) { 
                int nya=((row-1)*n)+col; if(!visited.count(nya)){
                lowest_value[((row-1)*n)+col]=min( lowest_value[nya],lowest_value[gg]+1);
                kwi.push(nya);
                visited.insert(nya);}
                } 
              if(row+1<m && grid[row+1][col]!=0) { 
                int nya=((row+1)*n)+col; if(!visited.count(nya)){
                lowest_value[((row+1)*n)+col]=min( lowest_value[nya],lowest_value[gg]+1);
                kwi.push(nya);
                visited.insert(nya);}
                } 
              if(col-1>=0 && grid[row][col-1]!=0) { 
                int nya=(row*n)+col-1; if(!visited.count(nya)){
                lowest_value[(row*n)+col-1]=min( lowest_value[nya],lowest_value[gg]+1);
                kwi.push(nya);
                visited.insert(nya);}
                } 
              if(col+1<n && grid[row][col+1]!=0) { 
                int nya=(row*n)+col+1; if(!visited.count(nya)){
                lowest_value[(row*n)+col+1]=min( lowest_value[nya],lowest_value[gg]+1);
                kwi.push(nya);
                visited.insert(nya);}
                } 
            }
        }

        int ans=0;
        for(auto& i:lowest_value){
            ans=max(i.second,ans);
        }
        if(ans==INT_MAX){return -1;}
        return ans;
    }
};