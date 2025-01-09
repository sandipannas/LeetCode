class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int count=0;
        for(auto i:words)
        {
            if(pref==i.substr(0,n))
            {
                count++;
            }

        }
    return count;}
};