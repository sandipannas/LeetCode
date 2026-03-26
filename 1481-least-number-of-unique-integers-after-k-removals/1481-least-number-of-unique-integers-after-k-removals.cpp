class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        priority_queue<int,vector<int>,greater<int>> filter;

        for(int i:arr){
            map[i]++;
        }
        for(auto& both:map){
            filter.push(both.second);
        }

        while(filter.size()>0){
            if(k<filter.top()){ return filter.size();}
            else if(k==filter.top()){return filter.size()-1;}
            else{
                k-=filter.top();
                filter.pop();
            }
        }

        return 0;
    }
};