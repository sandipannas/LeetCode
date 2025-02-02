class Solution {
public:
    int tribonacci(int n) {
        long val1=0,val2=1,val3=1;
        if(n==0){return 0;}
        if(n==1 || n==2){return 1;}
        for(int i=3;i<=n;i++)
        {
          int sum=val1+val2+val3;
          val1=val2;
          val2=val3;
          val3=sum;
        }
        return val3;
    }
};