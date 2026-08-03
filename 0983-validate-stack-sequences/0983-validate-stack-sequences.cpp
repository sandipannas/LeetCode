class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int pt=0;

        for(int i=0;i<pushed.size();i++){
            if(!stk.empty() && popped[pt]==stk.top()){ 
                stk.pop();  
                pt++; 
                i--;
            }
            else{ 
                stk.push(pushed[i]); 
            }
        }

        while(pt<popped.size()){
            if(stk.empty() || stk.top()!=popped[pt]) return false;
            stk.pop(); pt++;
        }

        return true;
    }
};