class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int pop_pt=0,push_pt=0;

        while(push_pt<pushed.size()){
            if(!stk.empty() && popped[pop_pt]==stk.top()){ 
                stk.pop();  
                pop_pt++; 
            }
            else{ 
                stk.push(pushed[push_pt++]); 
            }
        }

        while(pop_pt<popped.size()){
            if(stk.empty() || stk.top()!=popped[pop_pt]) return false;
            stk.pop(); pop_pt++;
        }

        return true;
    }
};