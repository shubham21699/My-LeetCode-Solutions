class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1) return 1;
        if(n == 2) return 1;
        
        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++) mp[arr[i]]++;
        
        priority_queue<int> pq;
        for(auto it=mp.begin() ; it!=mp.end() ; it++) pq.push(it->second);
        
        int count = 0;
        int size = n;
        
        while(!pq.empty()) {
            
            count++;
            size -= pq.top();
            pq.pop();
            
            if(size <= n/2) break;
            
        }
        
        return count;
    }
};