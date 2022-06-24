class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        if(n == 1) return (speed[0] * efficiency[0]) % mod;
        if(k == 1) {
            int maxPerf = 0;
            for(int i=0 ; i<n ; i++) maxPerf = max(maxPerf, (speed[i] * efficiency[i]) % mod);
            
            return maxPerf % mod;
        }
        
        vector<pair<int, int>> order(n);
        for(int i=0 ; i<n ; i++) order[i] = { efficiency[i], speed[i] };
        
        sort(order.rbegin(), order.rend());
        
        long long maxPerf = 0;
        long long totalSpeed = 0;
        priority_queue<int, vector<int>, greater<int>> sorder;
        
        for(auto p : order) {
            
            totalSpeed += p.second;
            sorder.push(p.second);

            if(sorder.size() > k) {
                totalSpeed -= sorder.top();
                sorder.pop();
            }
            
            maxPerf = max(maxPerf, totalSpeed * p.first);
        }
        
        return maxPerf % mod;
    }
};