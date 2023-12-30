class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int n = words.size();
        unordered_map<char, int> freq;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<words[i].length() ; j++) {
                freq[words[i][j]]++;
            }
        }
        
        // If frequency of each character is divisible by number of strings, means it can be equally
        // distributed among all strings and make all strings equal.
        for(auto it : freq) {
            if(it.second % n != 0) return false;
        }
        
        return true;
    }
};