class Solution {
public:
    int minSwaps(string s) {
      stack<char> gg;
      int swap=0;
      for(int i=0;i<s.size();i++)
      {
         if(gg.empty() && s[i]!='[')
         {
            swap++;
            gg.push('[');
         }
         else if(!gg.empty() && gg.top()=='[' && s[i]==']')
         {
            gg.pop();
         }
         else
         {
            gg.push(s[i]);
         }
      }
      return swap;
    }
};