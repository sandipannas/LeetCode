class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1=0;
        int p2=0;
        string ans="";
        while(p1<word1.size() && p2<word2.size())
        {
          ans+=word1[p1];
          ans+=word2[p2];
          p1++;
          p2++;
        }
        if(p1>=word1.size() && p2>=word2.size())
        {
            return ans;
        }
        else if(p1>=word1.size())
        {
            return ans+word2.substr(p2,word2.size()-p2);
        }
        else if(p2>=word2.size())
        {
            return ans+word1.substr(p1,word1.size()-p1);
        }
        return ans;
    }
};