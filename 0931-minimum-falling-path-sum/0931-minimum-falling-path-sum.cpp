class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dpDown(n,0);

        for(int i=m-1;i>=0;i--){
            vector<int> store(n,INT_MAX);
            for(int j=n-1;j>=0;j--){
                int left = j-1<0 || i+1>=m ?INT_MAX:dpDown[j-1];
                int down = i+1>=m ?INT_MAX:dpDown[j];
                int right = j+1>=n || i+1>=m ?INT_MAX:dpDown[j+1];
                int tem =matrix[i][j]+((left==down && down==right && left==right && right==INT_MAX)?0:min(left,min(down,right)));
                store[j]=tem;
            }
            dpDown=store;
        }
        int miin=INT_MAX;
        for(int i:dpDown){
            miin=min(i,miin);
        }
        return miin;
    }
};