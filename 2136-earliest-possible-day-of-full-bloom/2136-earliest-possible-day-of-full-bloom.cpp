class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int, int>> v;
        
        for(int i=0 ; i<n ; i++) v.push_back({ growTime[i], plantTime[i] });
        
        // Sort in decreasing order of growing time.
        sort(v.rbegin(), v.rend());
        
        int lastPlantTime = 0;
        int fullBloomTime = 0;
        
        for(int i=0 ; i<n ; i++) {
            lastPlantTime += v[i].second;
            fullBloomTime = max(fullBloomTime, lastPlantTime + v[i].first + 1);
        }
        
        // 0 based indexing of days so -1 to final result.
        return fullBloomTime-1;
    }
};