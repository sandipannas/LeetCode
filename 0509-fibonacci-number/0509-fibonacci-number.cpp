class Solution {
public:
    int fib(int n) {
       if(n<=1){return n;}
       int dp1=0,dp2=1,ans=-1;
       for(int i=2;i<=n;i++)
       {
         ans=dp1+dp2;
         dp1=dp2;dp2=ans;
       }
       return ans;
    }
};