class Solution {
public:
string ann="";
    void ans(string s,int i,int j)
    {
      int st=i;
      int ed=j;
      while(st>=0 && ed<s.size())
      {
        if(s[st]!=s[ed])
        {
            if(ann.size()<ed-st-1){ann=s.substr(st+1,ed-st-1);};
            return;
        }
        st--;
        ed++;
      }
      if(ann.size()<ed-st-1){ann=s.substr(st+1,ed-st-1);};
    }
    string longestPalindrome(string s) {
        ans(s,0,0);
        for(int i=1;i<s.size();i++)
        {
           ans(s,i,i);
           if(s[i]==s[i-1]){ans(s,i-1,i);}
        }
        return ann;
    }
};