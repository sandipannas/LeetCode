using item = pair<int, string>;//(rating, food), (rating, cuisine)
struct cmp {
    bool operator()(const item& x, const item& y) const {
        if (x.first == y.first) 
            return x.second > y.second;
        else 
            return x.first < y.first;
    }
};
class FoodRatings {
    unordered_map<string, priority_queue<item, vector<item>, cmp>> Rated;
    unordered_map<string, item> mp;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        int n=foods.size();
        for(int i=0; i<n; i++){
            string food=foods[i], cuisine=cuisines[i];
            int rating=ratings[i];
            mp[food]={rating, cuisine};
            Rated[cuisine].push({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [i, cuisine]  = mp[food];
        Rated[cuisine].push({newRating, food});
        mp[food]={newRating, cuisine};
    }
    
    string highestRated(string cuisine) {
        auto [i, food]=Rated[cuisine].top();
        while(mp[food].first!=i){
            Rated[cuisine].pop();
            tie(i, food)=Rated[cuisine].top();
        }
        return food;
    }
};
 auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();