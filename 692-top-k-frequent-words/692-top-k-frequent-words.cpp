class Solution {
public:
    struct Comp {
        bool operator()(const pair<int, string>& p1, const pair<int, string>& p2) const {
            if (p1.first != p2.first)
                return p1.first < p2.first;
            return p1.second > p2.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        if(n == 1) return words;
        
        unordered_map<string, int> mp;
        for(int i=0 ; i<n ; i++) mp[words[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comp> pq;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            pq.push({ it->second, it->first });
        }
        
        vector<string> res;
        while(!pq.empty() && k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return res;
    }
};