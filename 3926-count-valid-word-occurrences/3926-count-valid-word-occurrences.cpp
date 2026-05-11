class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string,int> map;
        string s="";
        for(string word : chunks){
            s+=word;
        }
        string valid="";

        for(int i=0;i<s.size();i++){
            if( (i==0 || i==s.size()-1) && s[i]=='-'){
                if(valid!=""){
                    map[valid]++;
                    valid="";
                }
            }
            else if(s[i]-'a'>=0 && s[i]-'a'<26){
                valid+=s[i];
            }
            else if(s[i]==' ' && valid!=""){
                map[valid]++;
                valid="";
            }
            else if(s[i]=='-' && (s[i-1]-'a'>=0 && s[i-1]-'a'<26) && (s[i+1]-'a'>=0 && s[i+1]-'a'<26)){
                valid+=s[i];
            }
            else if(valid!=""){
                map[valid]++;
                valid="";
            }
        }
        if(valid!=""){
                map[valid]++;
                valid="";
        }
        vector<int> answer;
        for(string i:queries){
            if(!map.count(i)){answer.push_back(0);}
            else{ answer.push_back(map[i]);}
        }
        return answer;
    }
};