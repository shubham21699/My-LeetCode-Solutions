class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        
        if(n < m) return "";
        
        unordered_map<char, int> mt;
        unordered_map<char, int> ms;
        
        for(int i=0 ; i<m ; i++) {
            mt[t[i]]++;
        }
        
        int start = 0;
        int start_index = -1;
        int min_length = INT_MAX;
        int count_of_t_chars = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            // If current character is present in pattern string, then only check for 
            // minimum window substring from current index.
            if(mt.find(s[i]) != mt.end()) {
                
                // Count occurrence of characters of string.
                ms[s[i]]++;
                
                // If current character matches with pattern string, then increment count.
                if(ms[s[i]] <= mt[s[i]]) count_of_t_chars++;
                
                // If all the characters are matched.
                if(count_of_t_chars == m) {
                    
                    // Try to minimize the window size.
                    while(ms[s[start]] > mt[s[start]] || mt[s[start]] == 0) {
                        if(ms[s[start]] > mt[s[start]]) {
                            ms[s[start]]--;
                        }
                        start++;
                    }
                    
                    // Update window size.
                    if(min_length > i-start+1) {
                        min_length = i-start+1;
                        start_index = start;
                    }
                    
                }
                
            }
            
        }
        
        // If no window found, return empty string.
        if(start_index == -1) return "";
        return s.substr(start_index, min_length);
        
        
//         OR: Will give TLE
//         string result = "";
        
//         for(int i=0 ; i<n ; i++) {
//             if(mt.find(s[i]) != mt.end()) {
                
//                 unordered_map<char, int> ms;
                
//                 for(int j=i ; j<n ; j++) {
//                     if(mt.find(s[j]) != mt.end() && mt[s[j]] > ms[s[j]]) {
//                         ms[s[j]]++;
//                     }
//                     if(mt == ms) {
//                         if(result.empty()) result = s.substr(i, j-i+1);
//                         else if(result.size() > j-i+1) result = s.substr(i, j-i+1);
//                         break;
//                     }
//                 }
                
//             }
//         }
        
//         return result;
    }
};