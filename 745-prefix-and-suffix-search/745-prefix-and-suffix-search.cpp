class WordFilter {
    unordered_map<string, int> mp;
    
public:
    WordFilter(vector<string>& words) {
        
        int n = words.size();
        
        for(int i=0 ; i<n ; i++) {
            
            string x = words[i];
            int m = x.length();
            
            for(int j=0 ; j<m ; j++) {
                string prefix = x.substr(0, j+1);
                
                for(int k=0 ; k<m ; k++) {
                    string suffix = x.substr(k, m-k);
                    
                    string y = prefix + "#" + suffix;
                    mp[y] = i;
                    
                }
                
            }
            
        }
        
    }
    
    int f(string prefix, string suffix) {
        
        string y = prefix + "#" + suffix;
        
        if(mp.find(y) != mp.end()) return mp[y];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */