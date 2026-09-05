class Solution {
public:
    string reverseParentheses(string s) {
        
        //meta gamming
        vector<int> stk;
        unordered_map<int,int> teleport;
        int count=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){ 
                stk.push_back(i);
                count++;
            }
            else if(s[i]==')'){
                teleport[i]=stk.back();
                teleport[stk.back()]=i;
                stk.pop_back();
                count++;
            }
        }

        int orient=1;
        string answer="";
        int st=0;
        while(answer.size()!=s.size()-count){
            if(s[st]=='(' || s[st]==')'){
                orient=-orient;
                st=teleport[st];
            }
            else{
                answer+=s[st];
            }

            st+=orient;
        }
        return answer;
    }
};