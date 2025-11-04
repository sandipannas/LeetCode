class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        int n=nums.size()-k+1;
        vector<int> answer(n);
        for(int i=0;i<n;i++){
            unordered_map<int,int> map;
            
            //cout<<"for index "<<i<<endl;

            for(int j=i;j<=i+k-1;j++){
                if(j>=nums.size()){continue;}
                //cout<<" "<<nums[j];
                map[nums[j]]++;
            }

            //cout<<endl;

            int sum=0;
            for(int j=0;j<x;j++){
                if(map.empty()){break;}
                int index=-1;
                int compare=-1;
                for(auto& pair:map){
                   if(pair.second>compare){
                    compare=pair.second;
                    index=pair.first;
                   }
                   else if(pair.second==compare && pair.first>index){
                    compare=pair.second;
                    index=pair.first;
                   }
                }
                //cout<<"the "<<x<<" most frequent is "<<index<<endl;
                sum+=index*compare;
                map.erase(index);

            }
            //cout<<" then for index "<<i<<"the sum is "<<sum<<endl;
            answer[i]=sum;
        }
        return answer;
    }
};