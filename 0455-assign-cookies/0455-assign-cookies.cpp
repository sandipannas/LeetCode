class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int st=0;
        int left=0;
        while(st<s.size() && left<g.size())
        {
            if(s[st]>=g[left])
            {
                st++;
                left++;
            }
            else{st++;}
            
        }
    return left;}
};