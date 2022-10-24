class Solution {
public:
    unordered_map<int, int> freq;
    
    void possibleLen(vector<string>& arr, int ind, int n, int& maxLen) {
        
        int len = 0;
        
        for(int i=0 ; i<26 ; i++) {
            if(freq[i] > 1) return;
            if(freq[i] == 1) len++;
        }
        
        maxLen = max(maxLen, len);
        
        for(int i=ind ; i<n ; i++) {
            for(auto c : arr[i]) freq[c-'a']++;
            
            possibleLen(arr, i+1, n, maxLen);
            
            for(auto c : arr[i]) freq[c-'a']--;
        }
        
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        int maxLen = 0;
        
        possibleLen(arr, 0, n, maxLen);
        return maxLen;
    }
};