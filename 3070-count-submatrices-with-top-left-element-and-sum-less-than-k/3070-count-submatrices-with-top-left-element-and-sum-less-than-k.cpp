class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
       vector<int> look(grid[0].size(),0);

       int count=0;
       
       for(int i=0;i<grid.size();i++){
        int sum=0;
        for(int j=0;j<grid[0].size();j++){
          sum+=grid[i][j];
          if(look[j]+sum<=k){ count++; }
          look[j]+=sum;
        }
       }

       return count; 
    }
};