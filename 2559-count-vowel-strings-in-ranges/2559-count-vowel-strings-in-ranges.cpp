class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size());
        int count=0;
        for(int i=0;i<words.size();i++){
            if((words[i][0]=='a' 
                || words[i][0]=='e' 
                || words[i][0]=='i' 
                || words[i][0]=='o' 
                || words[i][0]=='u') && 
               (words[i].back()=='a' 
                || words[i].back()=='e' 
                || words[i].back()=='i'
                || words[i].back()=='o' 
                || words[i].back()=='u')){
                count++;
            }
            prefix[i]=count;
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0){
                ans[i]=prefix[queries[i][1]];
            }
            else{
                ans[i]=prefix[queries[i][1]]-prefix[queries[i][0]-1];
            }
        }
        return ans;
        
    }
};