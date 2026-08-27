class Solution {
public:
    string simplifyPath(string path) {
        vector<string> canonical;

        path+="/";
        string tem="";
        for(char c:path){
           if(c=='/'){
                if(tem.empty()){ continue; }
                else if(tem=="."){ }
                else if(tem==".."){ 
                    if(!canonical.empty()) canonical.pop_back(); 
                }
                else{ canonical.push_back(tem); }
                tem="";
           }
           else{
            tem+=c;
           }
        }

        if(!tem.empty() && tem!="." && tem!=".."){ 
            canonical.push_back(tem); 
        }

        if(canonical.empty()) return "/";

        tem="";
        for(string s:canonical){
            tem+=("/"+s);
        }

        return tem;
    }
};