class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        int n = tasks.size();
        unordered_map<int, int> mp;
        
        for(int i=0 ; i<n ; i++) mp[tasks[i]]++;
        
        int count = 0;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            if(it->second == 1) return -1;

            if(it->second % 3 == 0) count += it->second / 3;
            else count += it->second/3 + 1;
        }
        
        return count;
    }
};