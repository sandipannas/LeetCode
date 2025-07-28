class Solution {
public:
    string processStr(string s) {
        string result=""; 
        for(char car:s){
            if(car=='*' && result!="") {result.erase(result.size()-1,1);}
            else if(car=='#') {result+=result;}
            else if(car=='%') {reverse(result.begin(),result.end());}
            else if(car!='*' && car!='#' && car!='%'){result+=car;}
        }
        return result;
    }
};