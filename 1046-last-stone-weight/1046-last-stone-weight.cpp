class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> pq;
      for(int i:stones)
      {
        pq.push(i);
      }
      while(pq.size()>1)
      {
        int big=pq.top();
        pq.pop();
        int small=pq.top();
        pq.pop();
        if(big!=small)
        {
            pq.push(big-small);
        }

      }
      if(pq.size()==0)
      {
        return 0;
      }  
      return pq.top();
    }
};