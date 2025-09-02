class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b) {
        if (a[0] == b[0]) 
            return a[1] > b[1];  
        return a[0] < b[0];      
        });
        int count=0;        
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                vector<int> a = points[i];
                vector<int> b = points[j];
                
                if(a[0]!=b[0] && a[1]<b[1]){
                    continue;
                }
                
                int flag=1;
                for(int k=0;k<points.size();k++){
                    if(k==i || k==j){ continue; } 
                    vector<int> p = points[k];
                    if((p[0]>=a[0] && p[0]<=b[0]) && (p[1]<=a[1] && p[1]>=b[1])){
                        flag=0;
                        break;
                    }
                }
                
                if(flag){
                count++;
                }

            }
        }
        return count;
    }
};