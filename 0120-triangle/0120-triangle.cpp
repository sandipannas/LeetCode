class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        vector<int> dpDown(triangle[m-1].size()+1);
        
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dpDown[j]=triangle[i][j]+min(dpDown[j],dpDown[j+1]);
            }
        }
        return dpDown[0];
    }
};