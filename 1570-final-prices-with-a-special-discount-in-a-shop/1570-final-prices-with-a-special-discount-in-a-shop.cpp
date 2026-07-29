class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>> stk;

        int i=0;
        while(i<prices.size()){
            if(!stk.empty() && stk.top().second>=prices[i]){
                
                int tem_value=stk.top().second-prices[i];
                int tem_index=stk.top().first;

                stk.pop();

                prices[tem_index]=tem_value;
            }
            else{
                stk.push({i,prices[i]});
                i++;
            }
        }

        return prices;
    }
};