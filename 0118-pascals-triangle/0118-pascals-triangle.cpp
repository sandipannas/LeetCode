class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> answer(numRows);
       for(int i=0;i<numRows;i++){
          vector<int> curr(i+1);
          curr[0]=1;curr[i]=1;
          for(int j=1;j<i;j++){
            curr[j]=answer[i-1][j-1]+answer[i-1][j];
          }
          answer[i]=curr;
         
       } return answer;
    }
};