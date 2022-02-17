class Solution {
    void make_sentence(string s, unordered_set<string> st, int n, vector<string>& result, int index, string res) {
        
        if(index >= n) {
            if(res.back() == ' ') res.pop_back();
            result.push_back(res);
            return;
        }
        
        string temp = "";
        
        for(int i=index ; i<n ; i++) {
            temp += s[i];
            if(st.find(temp) != st.end()) {
                make_sentence(s, st, n, result, i+1, res + temp + ' ');
            }
        }
        
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.length();
        int m = wordDict.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> result;
        
        make_sentence(s, st, n, result, 0, "");
        
        return result;
    }
};