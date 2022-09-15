class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n = changed.size();
        if(n % 2 != 0) return {};
         
        sort(changed.rbegin(), changed.rend());
        unordered_map<int, int> mp;
        vector<int> result;
        
        for(int i=0 ; i<n ; i++) {
            if(mp.find(changed[i] * 2) != mp.end()) {
                result.push_back(changed[i]);
                mp[changed[i] * 2]==1 ? mp.erase(changed[i] * 2) : mp[changed[i] * 2]--;
            }
            else mp[changed[i]]++;
        }
        
        return result.size() == (n/2) ? result : vector<int>();
    }
};