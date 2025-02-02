class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
       int var0=1;
       int var1=1;
        for(int i=2;i<=n;i++)
        {
           int var=var0+var1;
           var0=var1;
           var1=var;
           
        }
        return var1;
    }
};