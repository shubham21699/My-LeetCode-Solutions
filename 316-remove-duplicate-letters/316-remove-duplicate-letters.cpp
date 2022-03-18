class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.length();
        if(n == 1) return s;
        
        unordered_map<char, int> counts;
        unordered_map<char, bool> visited;
        
        // Stores count of each character
        for(int i=0 ; i<n ; i++) {
            counts[s[i]]++;
        }
        
        string result = "";
        
        for(int i=0 ; i<n ; i++) {
            
            // Decrease the count of current character
            counts[s[i]]--;
            
            // If character is not already in answer
            if(!visited[s[i]]) {
                
                // Last character > S[i] and its count > 0
                while(result.length() > 0 && result.back() > s[i] && counts[result.back()] > 0) {
                    // Mark letter unvisited
                    visited[result.back()] = false;
                    result.pop_back();
                }
                
                // Add s[i] in res and mark it visited
                result += s[i];
                visited[s[i]] = true;
                
            }
            
        }
        
        return result;
    }
};