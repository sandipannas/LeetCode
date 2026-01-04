class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
        int count=0;
        int temSum=0;
          for(int j=2;j<=pow(i,0.5);j++){
            if(i%j==0 && j*j!=i){ 
                if(j*j==i){ temSum+=j; count++; }
                else{ temSum+=j+(i/j); count+=2; }
            } 
          }
        if(count==2){
          sum+=temSum+1+i;
        }
        }
        return sum;
    }
};