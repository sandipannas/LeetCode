class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int>> gg;
        unordered_set<int> og;
        for(int i=0;i<s.size();i++)
        {
           if(!gg.count(s[i]))
           {
            gg.insert(make_pair(s[i],make_pair(i,-1)));
           }
           else
           {
            gg[s[i]].second=i;
           }
        }
        int coop=0;
        for(int i='a'-0;i<='z'-0;i++)
        {   og.clear();
            if(!gg.count((char)i))
           {
            continue;
           }
            int st=gg[(char)i].first;
            int ed=gg[(char)i].second;
            for(int j=st+1;j<ed;j++)
            {
                og.insert(s[j]);
            }
            coop+=og.size();
        }
   return coop;}
};