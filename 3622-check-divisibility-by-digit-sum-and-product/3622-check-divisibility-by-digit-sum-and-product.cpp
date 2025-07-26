class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int number=n;
        while(number>0){
          int ls=number%10;
          number=number/10;
          sum+=ls;
          pro*=ls;
        }
        sum+=pro;
        if(n%sum==0){return true;}
        return false;
    }
};