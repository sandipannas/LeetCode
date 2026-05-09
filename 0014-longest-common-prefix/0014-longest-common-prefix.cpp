class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer=strs[0];

        for(int i=1;i<strs.size();i++){
            if(answer.size()==0){return "";}

            int until=min(answer.size(),strs[i].size());
            answer=answer.substr(0,until);
            int count=0;
            while(count<until){
                if(answer[count]!=strs[i][count]){
                    answer=answer.substr(0,count);
                    break;
                }
                count++;
            }
        }

        return answer;

    }
};