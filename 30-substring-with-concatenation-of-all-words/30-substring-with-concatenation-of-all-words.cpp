class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.length();
        int m = words.size();
        int len = words[0].length();
        vector<int> result;
        
        unordered_map<string, int> ms, mw;
        for(int i=0 ; i<m ; i++) mw[words[i]]++;
        
        int j = 0;
        int k = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(i >= m*len-1) {
                
                k = j;
                ms.clear();
                
                while(k <= i) {
                    
                    string x = s.substr(k, len);
                    
                    if(mw.find(x) == mw.end()) break;
                    
                    ms[x]++;
                    k += len;
                }
                
                if(ms == mw) result.push_back(j);
                
                j++;
            }
            
        }
        
        return result;
    }
};