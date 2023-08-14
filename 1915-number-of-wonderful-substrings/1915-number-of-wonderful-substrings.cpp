class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        int n = word.length();
        long long freq[1024] = {1};
        long long count = 0;
        long long bit = 0;
        
        for(int i=0 ; i<n ; i++) {
            bit ^= 1 << (word[i] - 'a');
            count += freq[bit];
            
            for(int j=0 ; j<10 ; j++) {
                count += freq[bit ^ (1 << j)];
            }
            
            freq[bit]++;
        }
        
        return count;
    }
};