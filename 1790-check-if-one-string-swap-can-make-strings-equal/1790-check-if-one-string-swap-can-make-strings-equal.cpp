class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0;
        unordered_map<char,int> gg1;
        unordered_map<char,int> gg2;
        for(int i=97;i<=122;i++)
        {
            gg1.insert(make_pair(char(i),0));
            gg2.insert(make_pair(char(i),0));
        }
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
            gg1[s1[i]]++;
            gg2[s2[i]]++;
        }
        if(gg1!=gg2){return false;}
        if(count!=2 && count!=0){return false;}
        return true;
    }
};