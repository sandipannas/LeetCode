class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        vector<int> answer;

        for(int i:nums){map[i]++;}

        for(auto& both:map){
            pq.push({both.second,both.first});
        }

        for(int i=0;i<k;i++){
            if(pq.empty()){break;}
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};