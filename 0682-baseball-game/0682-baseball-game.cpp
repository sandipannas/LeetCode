class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stk;

        for(string s: operations){
            if((int)s.front()<65 && s.front()!='+'){
                int to_add=stoi(s);
                stk.push(to_add);
            }
            else if(s=="+"){
                int first=stk.top();
                stk.pop();
                int second=stk.top();
                stk.push(first);
                stk.push(first+second);
            }
            else if(s=="D"){
                stk.push(stk.top()*2);
            }
            else if(s=="C"){
                stk.pop();
            }
        }

        int answer=0;

        while(!stk.empty()){
            answer+=stk.top();
            stk.pop();
        }

        return answer;
    }
};