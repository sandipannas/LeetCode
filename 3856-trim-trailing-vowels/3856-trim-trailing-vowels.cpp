class Solution {
public:
    string trimTrailingVowels(string s) {
        int index=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
                index=i;
                break;
            }
        }

        return (index<0)?"":s.substr(0,index+1);

    }
};