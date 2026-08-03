class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int poppt=0,pushpt=0;

        while(pushpt<pushed.size()){
            if(!stk.empty() && popped[poppt]==stk.top()){ 
                stk.pop();  
                poppt++; 
            }
            else{ 
                stk.push(pushed[pushpt]); 
                pushpt++;
            }
        }

        while(poppt<popped.size()){
            if(stk.empty() || stk.top()!=popped[poppt]) return false;
            stk.pop(); poppt++;
        }

        return true;
    }
};