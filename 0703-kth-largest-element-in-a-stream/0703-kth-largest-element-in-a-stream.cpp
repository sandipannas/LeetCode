class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
           pq.push(nums[i]);
        }
        while(pq.size()>k)
        {
            pq.pop();
        }

    }
    
    int add(int val) {
        if(pq.size()==0)
        {
            pq.push(val);
        }
        if(val<pq.top())
        {
            return pq.top();
        }
        else
        {
            pq.pop();
            pq.push(val);
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */