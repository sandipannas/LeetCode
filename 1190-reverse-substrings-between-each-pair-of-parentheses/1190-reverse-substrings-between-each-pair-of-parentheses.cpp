class Solution {
public:
    string reverseParentheses(string s) {
        
        //meta gamming
        vector<int> stk;
        vector<int> teleport(s.size());

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){ 
                stk.push_back(i);
            }
            else if(s[i]==')'){
                teleport[i]=stk.back();
                teleport[stk.back()]=i;
                stk.pop_back();
            }
        }

        int orient=1;
        string answer="";
        int st=0;
        while(st<s.size()){
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