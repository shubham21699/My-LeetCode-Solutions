class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int len = order.length();
        unordered_map<char, int> m;
        
        for(int i=0 ; i<len ; i++) {
            m[order[i]] = i;
        }
        
        for(int i=0 ; i<words.size()-1 ; i++) {
            
            bool flag = false;
            int n = min(words[i].length(), words[i+1].length());
            
            for(int j=0 ; j<n ; j++) {
                if(m[words[i][j]] < m[words[i+1][j]]) {
                    flag = true;
                    break;
                }
                else if(m[words[i][j]] > m[words[i+1][j]]) return false;
            }
            
            if(flag == false && words[i].length() > words[i+1].length()) return false;
            
        }
        
        return true;
    }
};