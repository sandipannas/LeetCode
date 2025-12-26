class Solution {
public:
    int bestClosingTime(string customers) {
       vector<int> prefix;
       int count=0;
       for(char i:customers){
        if(i=='Y'){
          count++;
        }
        prefix.push_back(count);
       }
       int limit=INT_MAX;
       int answer=-1;

       for(int j=0;j<=customers.size();j++){
         //penalty=no customer before closing + yes customer after closing
         int yesBefore=(j==0)?0:prefix[j-1];
         int yesAfter=prefix[customers.size()-1]-yesBefore;
         int noBefore=j-yesBefore;
         
         int penalty=noBefore+yesAfter;
         if(limit>penalty){
            limit=penalty;
            answer=j;
         }

         //cout<<yesBefore<<"  "<<yesAfter<<endl;
       }
       return answer;
    }
};