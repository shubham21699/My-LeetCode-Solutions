class Solution {
public:
    void find(string s, string x, unordered_set<string>& st, int index, int n) {
        
        if(index >= n) return;
        
        for(int i=index ; i<n ; i++) {
            x += s[i];
            st.insert(x);
            find(s, x, st, i+1, n);
            x.pop_back();
        }
        
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int n = s.length();
        unordered_map<char, vector<int>> mp;
        
        // - Create an vector that stores indices for each character a-z in S
        // - Then for each word, do a binary search for next index for current character in word 
        //   that is greater than the index we last found for the alst character
        // - If it doesn't exist, word doesn't exist, otherwise continue to search for word
        
        for(int i=0 ;i<n ; i++) {
            mp[s[i]].push_back(i);
        }
        
        int count = 0;
        
        for(int i=0 ; i<words.size() ; i++) {
            
            int x = -1;
            bool found = true;
            
            for(int j=0 ; j<words[i].size() ; j++) {
                auto it = upper_bound(mp[words[i][j]].begin(), mp[words[i][j]].end(), x);
                if(it == mp[words[i][j]].end()) found = false;
                else x = *it;
            }
            
            if(found) count++;
            
        }
        
        return count;
        
        
//         // OR: Will give TLE
//         unordered_set<string> st;
//         string x = "";
        
//         find(s, x, st, 0, n);

//         int count = 0;
//         for(int i=0 ; i<words.size() ; i++) {
//             if(st.find(words[i]) != st.end()) count++;
//         }
        
//         return count;
    }
};