class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char> gg;
       unordered_map<char,char> og;
       for(int i=0;i<s.size();i++){
          if(gg.count(s[i]) && gg[s[i]]!=t[i]){return false;}
          if(og.count(t[i]) && og[t[i]]!=s[i]){return false;}
          gg[s[i]]=t[i];
          og[t[i]]=s[i];
       }
     return true;
    }
};