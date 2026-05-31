class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long sum=mass;
        for(int i:asteroids){
            if(sum<i){ return false;}
            sum+=(long long)i;
        }
        return true;     
    }
};