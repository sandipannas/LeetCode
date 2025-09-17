//space optimized
class Solution {
public:
    int fib(int n) {
       if(n==0 || n==1)return n;
       int dp0=0,dp1=1,ans=-1;    
      for(int i=2;i<=n;i++){
        ans=dp0+dp1;
        dp0=dp1; dp1=ans;
       }

       return ans;

    }
};