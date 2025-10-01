class Solution {
public:
    //space optimized solution
    int uniquePaths(int m, int n) {
       vector<int> dpRight(m,0);
       vector<int> dpDown(n,0);

       dpRight[m-1]=1;

       for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int down=dpDown[j];
            int right=dpRight[i];
            int tem=down+right;
            dpDown[j]=tem;
            dpRight[i]=tem;
        }
       }
       return dpDown[0];
    }
};