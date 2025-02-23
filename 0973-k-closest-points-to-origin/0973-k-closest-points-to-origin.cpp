class Solution {
public:
    double formula(vector<int>& gg){
        return sqrt((double)pow(gg[0],2)+(double)pow(gg[1],2));
    } 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<double,vector<double>,greater<double>> gg;
        unordered_map<double,vector<vector<int>>> oo;

        for(auto& i:points)
        {
            oo[formula(i)].push_back(i);
            gg.push(formula(i));
        }
        vector<vector<int>> ans;
        double pre=-1;
        while(k--)
        {   if(pre==gg.top()){continue;}
            ans.insert(ans.end(),oo[gg.top()].begin(),oo[gg.top()].end());
            //vector1.insert( vector1.end(), vector2.begin(), vector2.end() );
            pre=gg.top();
            gg.pop();
            
        }
          return ans;
    }
};