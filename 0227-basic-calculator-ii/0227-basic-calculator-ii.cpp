class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> sys;

        string coll="";

        for(int i=0;i<s.size();i++){
            char c=s[i];    
            if( c<'0' || c>'9' || i==s.size()-1 ){ 
                if(c==' ' && i!=s.size()-1){ continue; }
                if(i==s.size()-1 && c!=' '){ 
                    coll+=c;
                }    
                if(!sys.empty()){
                    char sign=sys.back();
                    if(sign=='/'){ 
                        nums.back()/=stoi(coll);  
                        sys.pop_back(); 
                    }
                    else if(sign=='*'){ 
                        nums.back()*=stoi(coll); 
                        sys.pop_back();    
                    }
                    else if(sign=='+'){ 
                        nums.push_back(stoi(coll)); 
                    }
                    else if(sign=='-'){ 
                        nums.push_back(-stoi(coll)); 
                        sys.back()='+';
                    }
                }
                else{
                    nums.push_back(stoi(coll)); 
                }
                coll=""; 
                sys.push_back(c);
            }
            else{
                coll+=c;
            }
        }

        int answer=0;
        for(int i:nums){
            answer+=i;
        }
        return answer;
    }
};