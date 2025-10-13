class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> match=words;
        for(int i=0;i<words.size();i++){
            sort(match[i].begin(),match[i].end());
        }
        int i=1;
        while(i<words.size()){
            if(match[i]==match[i-1]){
              words[i]="";
            }
            i++;
        }
        vector<string> answer;
        for(string j:words){
            if(j!=""){
                answer.push_back(j);
            }
        }
    return answer;
    }
};