class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<string> > result;
        
        if(n == 1) {
            result.push_back(strs);
            return result;
        }
        
        unordered_map<string, vector<string> > m;
        
        for(int i=0 ; i<n ; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        
        for(auto it=m.begin() ; it!=m.end() ; it++) {
            result.push_back(it->second);
        }
        
        return result;
        
//         OR: Will give TLE
//         for(int i=0 ; i<n ; i++) {
//             vector<string> v;
//             string x = strs[i];
//             sort(x.begin(), x.end());
            
//             for(int j=0 ; j<n ; j++) {
//                 string s = strs[j];
//                 sort(s.begin(), s.end());
                
//                 if(s == x) v.push_back(strs[j]);
//             }
            
//             sort(v.begin(), v.end());
//             result.push_back(v);
//         }
        
//         sort(result.begin(), result.end());
//         result.erase(unique(result.begin(), result.end()), result.end());
//         return result;
    }
};