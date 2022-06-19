class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        int n = products.size();
        sort(products.begin(), products.end());
        unordered_map<string, vector<string>> mp;
        
        for(int i=0 ; i<n ; i++) {
            string x = products[i];
            for(int j=0 ; j<x.length() ; j++) {
                mp[x.substr(0, j+1)].push_back(x);
            }
        }
        
        int m = searchWord.length();
        vector<vector<string>> result;
        
        for(int i=0 ; i<m ; i++) {
            string y = searchWord.substr(0, i+1);
            
            if(mp.find(y) == mp.end()) result.push_back({});
            else {
                if(mp[y].size() > 3) result.push_back({ mp[y].begin(), mp[y].begin()+3 });
                else result.push_back({ mp[y].begin(), mp[y].end() });
            }
            
        }
        
        return result;
    }
};