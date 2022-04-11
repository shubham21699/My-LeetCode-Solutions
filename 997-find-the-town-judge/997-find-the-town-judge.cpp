class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        int m = trust.size();
        if(m == 1) return trust[0][1];
        
        unordered_map<int, int> mp;
        for(int i=0 ; i<m ; i++) {
            mp[trust[i][0]]--; // If trust[i][0] knows trust[i][1]
            mp[trust[i][1]]++; // If trust[i][1] is known by trust[i][0]
        }
        
        for(int i=1 ; i<=n ; i++) {
            // If it comes n-1 times means it is the one who is known by everyone but he doesn't know anyone.
            if(mp[i] == n-1) return i;
        }
        
        return -1;
    }
};