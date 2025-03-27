class Solution {
public:
    bool check(string s,int i,int j){
        while(i<j){
           // cout<<s[i]<<" "<<s[j]<<endl;
            if(s[i]!=s[j])
             {return false;}
            i++; j--; 

        }
        return true;
    }
    bool validPalindrome(string s) {
        int st=0,ed=s.size()-1;
        while(st<ed){
            //cout<<s[st]<<" "<<s[ed]<<endl;
            if(s[st]!=s[ed]) { 
                if(check(s,st+1,ed) || check(s,st,ed-1))
                {
                    return true;
                }
                else{
                    return false;
                }
             }
             st++; ed--;
        }
    return true;}
};