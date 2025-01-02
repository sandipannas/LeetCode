class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int index=0;
        int sum=0;
        vector<int> og(words.size());
        for(auto s:words)
        {   int n=s.size()-1;
            if((s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u') &&
               (s[n]=='a'||s[n]=='e'||s[n]=='i'||s[n]=='o'||s[n]=='u'))
               {
                sum++;
                words[index]="1";
               }
               else
               {
                words[index]="0";
               }
               og[index]=sum;

               index++;
        }
        index=0;
        vector<int> gg(queries.size(),0);
        for(auto i:queries)
        {
           if(i[0]==i[1])
           {
            gg[index]=stoi(words[i[0]]);
           }
           else
           {
            gg[index]=og[i[1]]-og[i[0]]+stoi(words[i[0]]);
           }
           index++; 
        }
        return gg;
    }
};