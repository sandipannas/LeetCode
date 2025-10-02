class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        vector<int> dpDown(triangle[m-1].size()+1);
        
        for(int i=m-1;i>=0;i--){

            vector<int> store(triangle[i].size());

            for(int j=triangle[i].size()-1;j>=0;j--){
                int tem = triangle[i][j]+min(dpDown[j],dpDown[j+1]);
                store[j]=tem;
            }
            dpDown=store;
        }
        return dpDown[0];
    }
};