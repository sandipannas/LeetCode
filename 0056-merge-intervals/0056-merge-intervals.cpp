class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int left=0;
        int right=1;

        int st=intervals[0][0];
        int ed=intervals[0][1];

        vector<vector<int>> ans;

        while(right<intervals.size()){

            //cout<<st<<" "<<ed<<" "<<intervals[right][0]<<" "<<intervals[right][1]<<endl;

            //left eat the whole right
            //---------------
            //       ------
 
            if(st<=intervals[right][0] && ed>=intervals[right][1]){
                right++;
                cout<<1<<endl;
            }

            //cross
            //--------------
            //        -----------

            else if(st<=intervals[right][0] && ed<=intervals[right][1] && ed>=intervals[right][0]){
                ed=intervals[right][1];
                right++;
                cout<<2<<endl;
            }

            //nothing overlapping
            //--------------
            //                -------

            else if(ed<intervals[right][0]){
                ans.push_back({st,ed});
                st=intervals[right][0];
                ed=intervals[right][1];
                right++;
                cout<<3<<endl;
            }
        }

        ans.push_back({st,ed});


        return ans;
    }
};