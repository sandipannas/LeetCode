class Solution {
public:
    const int max_pos=2e5;
    int move_right(vector<int>& line, int s, int k){
        int ans=0;
        for(int r=0;r<=k;r++){
            int end=min(max_pos,s+r),rest=max(0,k-2*r);
            int start=max(0,s-rest);
            int cans=line[end];
            if(start>0)
                cans-=line[start-1];
            ans=max(ans,cans);
        }
        return ans;
    }
    int move_left(vector<int>& line, int s, int k){
        int ans=0;
        for(int l=0;l<=k;l++){
            int start=max(0,s-l),rest=max(0,k-2*l);
            int end=min(s+rest,max_pos);
            int cans=line[end];
            if(start>0)
                cans-=line[start-1];
            ans=max(ans,cans);
        }
        return ans;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int s, int k) {
        vector<int> number_line(max_pos+1);
        for(auto &fruit:fruits){
            int pos=fruit[0],cnt=fruit[1];
            number_line[pos]+=cnt;
        }
        for(int i=1;i<=max_pos;i++)
            number_line[i]+=number_line[i-1];
        int ans1=move_right(number_line,s,k);
        int ans2=move_left(number_line,s,k);
        return max(ans1,ans2);
    }
};