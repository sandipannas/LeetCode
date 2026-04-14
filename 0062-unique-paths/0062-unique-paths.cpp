class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> right(m,0);
        vector<int> down(n,0);

        right[m-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int ways=right[i]+down[j];
                right[i]=ways; down[j]=ways;
            }
        }

        return right[0];
    }
};