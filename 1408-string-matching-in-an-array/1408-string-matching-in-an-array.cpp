class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> gg;
        unordered_set<string> og;
        if(words.size()==1)
        {
            return gg;
        }
        sort(words.begin(), words.end(),
          [](const string a, const string b) {
          return size(a) < size(b);});
       int flag=0;
       for(int i=0;i<words.size()-1;i++)
       {
        for(int j=i+1;j<words.size();j++)
        {   
            int n=words[i].size();
            int st=0;
            while(st<=words[j].size()-n)
            {   cout<<words[j].substr(st,n)<<" "<<words[i]<<"\n";
                if(words[j].substr(st,n)==words[i] && (!og.count(words[i])))
                {
                    gg.push_back(words[i]);
                    og.insert(words[i]);
                }
                else{
                    st++;
                }
            }
            
        }
       }
    return gg;
    }
};