class Twitter {
public:

    unordered_map< int, vector<pair<int,int>> >  posts;
    unordered_map< int, unordered_set<int> > friends;
    int time=0;

    Twitter() {
         
    }
    
    void postTweet(int userId, int tweetId) {
     
     time++;
     posts[userId].push_back({time,tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue< pair<int,int>, vector<pair<int,int>> > filter;

        for(int id:friends[userId]){
            int limit=posts[id].size();
            int count=min(limit,10);

            while(count--){
                filter.push(posts[id][limit-1]);
                limit--;
            }
        }

        int limit=posts[userId].size();
        int count=min(limit,10);
        while(count--){
            filter.push(posts[userId][limit-1]);
            limit--;
        }

        vector<int> revector;
        count=min((int)filter.size(),10);
        
        while(count--){
            revector.push_back(filter.top().second);
            filter.pop();
        }

        return revector;
        

    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */