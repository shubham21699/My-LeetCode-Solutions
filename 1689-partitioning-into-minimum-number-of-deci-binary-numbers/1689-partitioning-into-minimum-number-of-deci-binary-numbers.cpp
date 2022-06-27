class Solution {
public:
    int minPartitions(string num) {
        
        int n = num.length();
        int maxi = 0;
        
        for(int i=0 ; i<n ; i++) {
            maxi = max(maxi, num[i]-'0');
        }
        
        return maxi;
    }
};