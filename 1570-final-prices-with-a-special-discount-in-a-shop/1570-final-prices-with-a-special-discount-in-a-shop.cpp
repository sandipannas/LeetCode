class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;

        int i=0;
        while(i<prices.size()){
            if(!stk.empty() && prices[stk.top()]>=prices[i]){
                
                int tem_value=prices[stk.top()]-prices[i];
                int tem_index=stk.top();

                stk.pop();

                prices[tem_index]=tem_value;
                continue;
            }
            stk.push(i);
            i++;
        }

        return prices;
    }
};