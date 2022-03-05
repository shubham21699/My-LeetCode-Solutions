class Solution {
public:
    string longestWord(vector<string>& words) {
        
        int n = words.size();
        if(n == 1) return words[0];
        
        sort(words.begin(), words.end());
        unordered_set<string> st;
        string result = "";
        
        for(int i=0 ; i<n ; i++) {
            if(words[i].length() == 1 || st.find(words[i].substr(0, words[i].length()-1)) != st.end()) {
                result = words[i].length() > result.length() ? words[i] : result;
                st.insert(words[i]);
            }
        }
        
        return result;
    }
};