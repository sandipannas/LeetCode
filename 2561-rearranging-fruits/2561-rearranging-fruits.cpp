class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size(); int small=INT_MAX; long long answer=0;
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;


        for(int i=0;i<n;i++){
            map1[basket1[i]]++;
            map2[basket2[i]]++;
            small=min(small,min(basket1[i],basket2[i]));
        }

        vector<int> from1;
        vector<int> from2;
        
        for(int i=0;i<n;i++){
            if(
                (map1[basket1[i]]+map2[basket1[i]])%2==1 ||
                (map1[basket2[i]]+map2[basket2[i]])%2==1
            )
            { return -1; }
            
            if(map1[basket1[i]]>map2[basket1[i]]){
                while(map1[basket1[i]]!=map2[basket1[i]]){
                    from1.push_back(basket1[i]);
                    map1[basket1[i]]--;
                    map2[basket1[i]]++;
                }
            }
            else{
                while(map1[basket1[i]]!=map2[basket1[i]]){
                    from2.push_back(basket1[i]);
                    map2[basket1[i]]--;
                    map1[basket1[i]]++;
                }
            }
            if(map1[basket2[i]]>map2[basket2[i]]){
                while(map1[basket2[i]]!=map2[basket2[i]]){
                    from1.push_back(basket2[i]);
                    map1[basket2[i]]--;
                    map2[basket2[i]]++;
                }
            }
            else{
                while(map1[basket2[i]]!=map2[basket2[i]]){
                    from2.push_back(basket2[i]);
                    map2[basket2[i]]--;
                    map1[basket2[i]]++;
                }
            }
        }
        sort(from1.begin(),from1.end());
        sort(from2.begin(),from2.end());

        int left=0;
        int right=from1.size()-1;
         
        while(right>=0){
            answer+=min(min(from1[left],from2[right]),small+small);
            left++; right--;
        }


        return answer;
    }
};