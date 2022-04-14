class Twitter {
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, set<int>> following;
    long long int time = 0;
    
public:
    Twitter() {
        posts.clear();
        following.clear();
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        
        posts[userId].push_back({ time++, tweetId });
        
    }
    
    /*  Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed 
        must be posted by users who the user followed or by the user herself. Tweets must be ordered 
        from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int, int>> pq;
        
        for(auto it=posts[userId].begin() ; it!=posts[userId].end() ; it++) {
            pq.push(*it);
        }
        
        for(auto it1=following[userId].begin() ; it1!=following[userId].end() ; it1++) {
            int itsFollower = *it1;
            for(auto it2=posts[itsFollower].begin() ; it2!=posts[itsFollower].end() ; it2++) {
                pq.push(*it2);
            }
        }
        
        vector<int> result;
        
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            if(result.size() == 10) return result;
            pq.pop();
        }
        
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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