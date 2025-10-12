class Solution {
public:
    bool scoreBalance(string s) {
        int total=0;
        vector<int> sub(s.size(),0);

        for(int i=0;i<s.size();i++){
            total+=s[i]-97+1;
            sub[i]=total;
        }
        
        int div=sub[s.size()-1];
        for(int i:sub){
            if(div/i==2 && div%i==0){
                return true;
            }
        }
        return false;
    }
};