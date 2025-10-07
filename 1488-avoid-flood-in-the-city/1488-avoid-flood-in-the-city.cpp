class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
      map<int, int> wet;
       priority_queue<int, vector<int>,greater<int>> dry;
        vector<int> ans(n, -1);


        for(int i=0; i<n; i++){
            if(rains[i] == 0){
                dry.push(i);
            }
            else{
                if(wet.count(rains[i]) == 0){
                    wet[rains[i]] = i;
                }
                else{
                    if(dry.size() > 0){
                        vector<int> temp;
                        while(!dry.empty() && dry.top() < wet[rains[i]]){
                            if(dry.top() < wet[rains[i]])temp.push_back(dry.top());
                            dry.pop();
                        }
                        if(dry.size() == 0){
                            return {};
                        }
                        else{
                            ans[dry.top()] = rains[i];
                            dry.pop();
                            // wet.erase(rains[i]);
                            wet[rains[i]] =i;
                            for(int i=0; i<temp.size(); i++){
                                dry.push(temp[i]);
                            }
                        }

                    }
                    else{
                        return {};
                    }
                }
            }

        }
        while(!dry.empty()){
            ans[dry.top()] =1;
            dry.pop();
        }
        return ans;
    }
};