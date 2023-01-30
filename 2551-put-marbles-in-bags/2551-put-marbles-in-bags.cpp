class Solution {
public:
    void distribution(vector<int>& weights, int i, int n, int k, long long sum, long long& maxi, long long& mini) {
        
        if(i >= n && k == 0) {
            maxi = max(maxi, sum);
            mini = min(mini, sum);
            return;
        }
        if(k == 0) return;
        
        for(int j=i ; j<n ; j++) {
            distribution(weights, j+1, n, k-1, sum + weights[i] + weights[j], maxi, mini);
        }
        
    }
    
    long long putMarbles(vector<int>& weights, int k) {
        
        int n = weights.size();
        if(k == 1 || k == n) return 0;
        
        vector<int> v;
        for(int i=0 ; i<n-1 ; i++) {
            v.push_back(weights[i] + weights[i+1]);
        }
        
        sort(v.begin(), v.end());
        
        long long maxi = 0, mini = 0;
        
        for(int i=0 ; i<k-1 ; i++) {
            mini += v[i];
            maxi += v[v.size() - 1 - i];
        }
        
        return maxi - mini;
        
        
//         // OR: Will give TLE
//         long long maxi = INT_MIN;
//         long long mini = INT_MAX;
//         distribution(weights, 0, n, k, 0, maxi, mini);
        
//         return maxi - mini;
    }
};