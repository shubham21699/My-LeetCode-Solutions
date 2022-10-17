class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int n = sentence.size();
        unordered_map<char, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            mp[sentence[i]]++;
        }
        
        return mp.size() == 26;
    }
};