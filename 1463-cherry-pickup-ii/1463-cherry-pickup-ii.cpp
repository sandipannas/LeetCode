class Solution {
public:
    int recur(int i,int j1,int j2,int m,int n,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=n || j2<0 || j2>=n){
            //cout<<"out of bounds "<<"\n";
            return INT_MIN;
        }
        if(i==m-1){
            if(j1==j2){return grid[i][j1];}
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){ return dp[i][j1][j2]; }

        int maxx=INT_MIN;
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                 maxx=max(maxx,recur(i+1,j1+a,j2+b,m,n,grid,dp));
            }
        }

        if(j1==j2){
            return dp[i][j1][j2]=grid[i][j1]+maxx;
        }
        else{
            return dp[i][j1][j2]=grid[i][j1]+grid[i][j2]+maxx;
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int>(n,-1)));
        return recur(0,0,n-1,m,n,grid,dp);
    }
};