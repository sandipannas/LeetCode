class Solution {
public:
    string removeStars(string s) {
        //stack<char> gg;
        string gg="";
        for(char i:s)
        {
            if(i=='*') { gg.pop_back(); continue;}
            gg.push_back(i);

        }
        //s="";
        //while(!gg.empty()){ s=s+gg.top(); gg.pop(); }
        //reverse(s.begin(),s.end());
        return gg;
    }
};