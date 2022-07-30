class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        int n = words1.size();
        int m = words2.size();
        vector<string> res;
        
        vector<int> maxFreq(26);
        for(int i=0 ; i<m ; i++) {
            
            vector<int> freq(26);
            for(auto c : words2[i]) freq[c-'a']++;
            
            for(int i=0 ; i<26 ; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
            
        }
    
        
        for(int i=0 ; i<n ; i++) {
            
            vector<int> freq(26);
            for(auto c : words1[i]) freq[c-'a']++;
            
            bool flag = true;
            
            for(int i=0 ; i<26 ; i++) {
                if(freq[i] < maxFreq[i]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) res.push_back(words1[i]);
        }
        
        return res;
    }
};