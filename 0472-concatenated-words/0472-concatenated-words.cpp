class Solution {
public:
    bool isConcatenated(string& s, unordered_set<string>& st, int i, int n, int partitions) {
        
        if(i >= n && partitions >= 2) return true;
        if(i >= n) return false;
        
        bool ans = false;
        
        for(int j=i ; j<n ; j++) {
            string x = s.substr(i, j-i+1);
            if(st.find(x) != st.end()) {
                ans |= isConcatenated(s, st, j+1, n, partitions+1);
            }
        }
        
        return ans;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        int n = words.size();
        vector<string> result;
        unordered_set<string> st(words.begin(), words.end());
        
        for(int i=0 ; i<n ; i++) {
            if(isConcatenated(words[i], st, 0, words[i].length(), 0)) result.push_back(words[i]);
        }
     
        return result;
    }
};