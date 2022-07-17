class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int q = queries.size();
        vector<int> result(q, 0);
        
        for(int i=0 ; i<q ; i++) {
            
            priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> pq;
            int k = queries[i][0];
            int trim = queries[i][1];
            int x = nums[0].length();
            
            for(int j=0 ; j<n ; j++) {
                string s = nums[j].substr(max(0, x-trim));
                pq.push({ s, j });
            }
            
            while(k > 1 && !pq.empty()) {
                pq.pop();
                k--;
            } 
            
            if(!pq.empty()) result[i] = pq.top().second;
        }
        
        return result;
        
//         // OR: Giving TLE
//         unordered_map<int, priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>>> mp;
        
//         for(int i=0 ; i<n ; i++) {
//             string s = nums[i];
//             int k = s.length();
//             int j = 0;
//             while(j < k) {
//                 string x = s.substr(j);
//                 mp[k-j].push({ x, i });
//                 j++;
//             }
//         }
        
//         for(int i=0 ; i<q ; i++) {
//             if(queries[i][0] > n) continue;
            
//             if(mp.find(queries[i][1]) != mp.end()) {
//                 priority_queue<pair<string, int>, vector<pair<string, int>>, greater<pair<string, int>>> p = mp[queries[i][1]];
                
//                 int x = queries[i][0]-1;
//                 while(x > 0 && !p.empty()) {
//                     p.pop();
//                     x--;
//                 }
                
//                 if(!p.empty()) result[i] = p.top().second;
//             }
//         }
        
//         return result;
    }
};