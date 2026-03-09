class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int limit=0;

    KthLargest(int k, vector<int>& nums) {
        limit=k;
        for(int i : nums){
           if(minHeap.size()==limit && minHeap.top()<i){
              minHeap.pop();
              minHeap.push(i);
           }
           else if(minHeap.size()<limit){
              minHeap.push(i);
           }
        }
    }
    
    int add(int val) {
        if(minHeap.size()==limit && minHeap.top()<val){
            minHeap.pop();
            minHeap.push(val);
        } 
        else if(minHeap.size()<limit){
            minHeap.push(val);
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */