class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        int n = words.size();
        if(n == 1) return words[0].length()+1;
        
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.length() > b.length();
        });
        
        unordered_set<string> st;
        for(int i=0 ; i<n ; i++) st.insert(words[i]);
        
        unordered_map<string, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            
            if(st.find(words[i]) == st.end()) continue;
            
            for(int j=0 ; j<words[i].length() ; j++) {
                string x = words[i].substr(j);
                
                if(st.find(x) != st.end()) {
                    mp[words[i]]++;
                    st.erase(x);
                }
            }
        }
        
        int minLen = 0;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            minLen += (it->first.length() + 1);
        }
        
        return minLen;
    }
};