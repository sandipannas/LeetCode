class Solution {
public:
    int bestClosingTime(string customers) {
       int penalty=0,minPenalty=0;
       int answer=0;

       for(int j=1;j<=customers.size();j++){
          int toAdd = customers[j-1]=='N'?1:-1;
          penalty+=toAdd;

          if(minPenalty>penalty){
            minPenalty=penalty;
            answer=j;
          }
       }
       return answer;
    }
};