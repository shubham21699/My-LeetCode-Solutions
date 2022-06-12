class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        int n = ideas.size();
        unordered_set<string> st[26];

        for(int i=0 ; i<n ; i++) {
            st[ideas[i][0] - 'a'].insert(ideas[i].substr(1));
        }
        
        long long result = 0;
        
        for(int i=0 ; i<26 ; i++) {
            for(int j=i+1 ; j<26 ; j++) {
                long long counti = 0;
                long long countj = 0;
                
                for(auto x : st[i]) {
                    if(st[j].find(x) == st[j].end()) counti++;
                }
                
                for(auto y : st[j]) {
                    if(st[i].find(y) == st[j].end()) countj++;
                }
                
                result += counti * countj;
            }
        }
        
        return result*2;
    }
};