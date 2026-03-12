class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> map;
        priority_queue<int,vector<int>> pq;
        queue<pair<int,int>> q;
        int time=0; 

        for(char i : tasks){ map[i]++; }
        for(auto& both : map){ pq.push(both.second); }

        while(pq.size()!=0 || q.size()!=0){
            
            if(q.size()!=0 && q.front().second==time){
               pq.push(q.front().first);
               q.pop();
            }

            if(pq.size()!=0){
                int done=pq.top();
                done--;
                if(done!=0){
                    q.push({done,time+n+1});
                }
                pq.pop();
            }

            time++; 
        }
        return time;
    }
};