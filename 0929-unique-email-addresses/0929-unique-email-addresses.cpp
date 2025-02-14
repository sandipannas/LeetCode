class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> gg;
        for(string i:emails){
            string s="";
            int flag=0;
            for(char j:i){ 
              if(j=='+' && flag==0){ flag=1;}
              if(j=='@'){flag=-1;}
              if(j!='.' && flag!=1){s.push_back(j);}
              else if(flag==-1){s.push_back(j);}
              
            }
            //cout<<s<<endl;
            gg.insert(s);
        }
        return gg.size();
    }
};