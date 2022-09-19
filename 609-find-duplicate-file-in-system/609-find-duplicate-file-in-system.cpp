class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        int n = paths.size();
        vector<vector<string>> result;
        
        unordered_map<string, vector<pair<string, string>>> mp;
        
        for(int i=0 ; i<n ; i++) {
            string x = paths[i];
            string p = "";
            
            int j = 0;
            while(x[j] != ' ') {
                p += x[j];
                j++;
            }
            while(x[j] == ' ') j++;
            
            string content = "";
            string num = "";
            
            for(int k=j ; k<x.length() ; k++) {
                if(x[k-1] == ' ' && x[k] != ' ') {
                    while(x[k] != '.') {
                        num += x[k];
                        k++;
                    }
                }
                if(x[k] == '(') {
                    k++;
                    while(x[k] != ')') {
                        content += x[k];
                        k++;
                    }
                    
                    mp[content].push_back({ p, num });
                    content = "";
                    num = "";
                }
            }
            
        }
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            
            vector<string> v;
            string x = "";
            auto k = it->second;
            
            // If no duplicates for this(it->first) content
            if(k.size() == 1) continue;
            
            for(int i=0 ; i<k.size() ; i++) {
                
                auto p = k[i];
                x += p.first;
                x += "/";
                x += p.second;
                x += ".txt";
                v.push_back(x);
                x = "";
            }
            
            result.push_back(v);
        }
        
        return result;
    }
};