class TweetCounts {
    unordered_map<string, vector<int>> tweets;
    unordered_map<string, int> timePeriod = {
        { "minute", 60 },
        { "hour", 3600 },
        { "day", 86400 }
    };
    
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        
        vector<int> result((endTime - startTime) / timePeriod[freq] + 1, 0);
        
        for(auto time : tweets[tweetName]) {
            if(time >= startTime && time <= endTime) {
                int index = (time - startTime) / timePeriod[freq];
                result[index]++;
            }
        }
        
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */