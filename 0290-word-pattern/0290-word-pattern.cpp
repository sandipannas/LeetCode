class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> gg;
        unordered_set<string> oo;
        string str="";
        vector<string> words;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '){ words.push_back(str); str=""; continue; }
            str=str + s[i];
            if(i==s.size()-1){ words.push_back(str); }
        }
        if(pattern.size() != words.size()){ return false; }
        
        for(int i=0;i<pattern.size();i++){
            if(gg.count(pattern[i]) && gg[pattern[i]]!=words[i]){return false;}
            else{
                gg[pattern[i]]=words[i];
            }
        }
        for(auto& pai:gg){
            if(oo.count(pai.second)){
                return false;
            }
            oo.insert(pai.second);
        }
    return true;}
};