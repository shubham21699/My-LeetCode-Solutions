class Solution {
public:
    int kthFactor(int n, int k) {
        
        int kth_factor = -1;
        
        for(int i=1 ; i<=n && k>0 ; i++) {
            if(n % i == 0) {
                kth_factor = i;
                k--;
            }
        }
        
        if(k > 0) return -1;
        return kth_factor;
    }
};