class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length();
        int count = 0; // Count number of 0101... order
        
        for(int i=0 ; i<n ; i++) {
            if(i%2 == 0 && s[i] == '0') count++;
            else if(i%2 == 1 && s[i] == '1') count++;
        }
        
        // Returning this count means string is having maximum in 1010... order,
        // Else returning n-count means string is having maximum in 0101... order.
        return min(count, n-count);
    }
};