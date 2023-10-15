class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        vector<string> result;
        result.push_back(words[0]);
        
        for(int i=1 ; i<n ; i++) {
            if(groups[i] != groups[i-1]) result.push_back(words[i]);
        }
        
        return result;
    }
};