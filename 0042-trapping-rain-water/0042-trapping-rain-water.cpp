class Solution {
public:
    int trap(vector<int>& h) {
        vector<int> limit;
        
        int pre=h[0];
        for(int i=0;i<h.size();i++){
            if(pre<h[i]) pre=h[i];
            limit.push_back(pre);
        }

        int right=h.back(); int sum=0;
        for(int i=h.size()-1;i>=0;i--){
            if(right<h[i]) right=h[i];
            sum+=min(limit[i],right)-h[i];
        }
        return sum;
    }
};