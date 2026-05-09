class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> maps;
        unordered_map<char,int> mapt;

        if(s.size()!=t.size()){ return false;}

        for(int i=0;i<s.size();i++){
            maps[s[i]]++;
            mapt[t[i]]++;
        }

        for(auto& both : maps){
            if(both.second!=mapt[both.first]){return false;}
        }

        return true;
    }
};