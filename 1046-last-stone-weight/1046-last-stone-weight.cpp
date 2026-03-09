class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int,vector<int>> maxHeap;

        for(int i:stones){
            maxHeap.push(i);
        }

        while(maxHeap.size()>1){
            int a=maxHeap.top();
            maxHeap.pop();

            int b=maxHeap.top();
            maxHeap.pop();

            if(a!=b){ maxHeap.push(a-b); }
        }

        return maxHeap.size()==0?0:maxHeap.top();
    }
};