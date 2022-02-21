class Solution {
public:
    int getMaximumGenerated(int n) {
        
        if(n <= 1) return n;
        
        vector<int> v(n+1);
        v[0] = 0;
        v[1] = 1;
        
        for(int i=2 ; i<=n ; i++) {
            v[i] = i%2==0 ? v[i/2] : v[i/2] + v[i/2 + 1];
        }
        
        return *max_element(v.begin(), v.end());
    }
};