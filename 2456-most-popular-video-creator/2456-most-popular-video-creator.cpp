class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        int n = creators.size();
        unordered_map<string, long long> mp;
        long long maxViews = 0;
        
        for(int i=0 ; i<n ; i++) {
            mp[creators[i]] += views[i];
            maxViews = max(maxViews, mp[creators[i]]);
        }
        
        map<string, vector<pair<int, string>>> highestViewCeleb;
        
        for(int i=0 ; i<n ; i++) {
            if(mp[creators[i]] == maxViews) {
                highestViewCeleb[creators[i]].push_back({ views[i], ids[i] });
            }
        }
        
        vector<vector<string>> result;
        
        for(auto it=highestViewCeleb.begin() ; it!=highestViewCeleb.end() ; it++) {
            auto v = it->second;
            sort(v.begin(), v.end(), [](pair<int, string>& a, pair<int, string>& b) {
                if(a.first == b.first) return a.second < b.second;
                return a.first > b.first;
            });
            result.push_back({ it->first, v[0].second });
        }
        
        return result;
    }
};