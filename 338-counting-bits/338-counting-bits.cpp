class Solution {
    int counting(int n) {
        
        int count = 0;
        
        while(n) {
            if(n&1) count++;
            n /= 2;
        }
        
        return count;
    }
    
public:
    vector<int> countBits(int n) {
        
        if(n == 0) return { 0 };
        if(n == 1) return { 0, 1 };
        if(n == 2) return { 0, 1, 1 };
        
        vector<int> ans(n+1, 0);
        ans[1] = ans[2] = 1;
        
        for(int i=3 ; i<=n ; i++) {
            // Faster method : This will reduce number of 1's by one, so adding 1 to it
            // Ex.    i = 14 --> 1 1 1 0
            //      i-1 = 13 --> 1 1 0 1
            // i&(i-1) => 12 --> 1 1 0 0
            ans[i] = ans[i&(i-1)] + 1; 
            
            // OR:
            // ans[i] = counting(i);
        }
        
        return ans;
    }
};