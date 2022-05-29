class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n = words.size();
        sort(words.begin(), words.end());
        if(words[0][0] == words[n-1][0]) return 0;
        
        vector<int> bitmask(n);
        
        for(int i=0 ; i<n ; i++) {
            for(char c : words[i]) {
                bitmask[i] |= (1 << (c-'a'));
            }
        }
        
        int result = 0; 
        
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                if((bitmask[i] & bitmask[j]) == 0) {
                    result = max(result, int(words[i].length() * words[j].length()));
                }
            }
        }
        
        return result;
    }
};