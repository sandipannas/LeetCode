class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& subs, vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int> next_g;
        vector<int> stk; stk.reserve(n);

        for(int i: views::reverse(nums)){
            while(!stk.empty() && stk.back()<=i){
                    stk.pop_back();
            }

            next_g[i]=stk.empty()?-1:stk.back();    
            stk.push_back(i);
        }

        vector<int> answer;

        for(int i:subs){
            answer.push_back(next_g[i]);
        }

        return answer;

    }
};