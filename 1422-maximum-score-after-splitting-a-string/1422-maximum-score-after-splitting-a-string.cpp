class Solution {
public:
    int maxScore(string s) {
      int one=0;
      int zero=0;
      vector<pair<int,int>> gg;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='0')
        {
            zero++;
        }
        pair<int,int> temp;
        gg.push_back(temp);
        gg[i].first=zero;
      }
      for(int i=s.size()-1;i>=0;i--)
      {
        if(s[i]=='1')
        {
            one++;
        }
        gg[i].second=one;
      }
      
      int maax=0;
      for(int i=0;i<s.size()-1;i++)
      {
        maax=max(gg[i].first+gg[i+1].second,maax);
      }

    return maax;}
};