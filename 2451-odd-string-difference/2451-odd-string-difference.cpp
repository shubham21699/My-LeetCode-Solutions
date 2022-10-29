class Solution {
public:
    string oddString(vector<string>& words) {
        
        int n = words.size();
        int m = words[0].length();
        map<vector<int>, vector<string>> mp;
        string result = "";
        
        for(int i=0 ; i<n ; i++) {
            vector<int> v;
            for(int j=1 ; j<m ; j++) {
                int x = (words[i][j]-'a') - (words[i][j-1]-'a');
                v.push_back(x);
            }
            mp[v].push_back(words[i]);
        }
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            if(it->second.size() == 1) {
                result = it->second[0];
                break;
            }
        }
        
        return result;
    }
};