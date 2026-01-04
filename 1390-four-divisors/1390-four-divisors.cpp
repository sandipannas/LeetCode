class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long sum=0;
        for(int i:nums){
        int count=0;
        int temSum=0;
          for(int j=2;j<=pow(i,0.5);j++){
            if(i%j==0){ 
                if(j*j==i){ temSum+=j; count++; }
                else{ temSum+=j+(i/j); count+=2; }
            } 
          }
        if(count==2){
          sum+=(long long)temSum+1+i;
        }
        }
        return sum;
    }
};