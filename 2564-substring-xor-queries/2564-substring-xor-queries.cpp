class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        
        int n = s.length();
        int q = queries.size();
        unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> mp;
        
        for(int i=n-1 ; i>=0 ; i--) {
            int num = 0;
            int k = 0;
            
            for(int j=i ; j>=0 && (i-j) <= 30 ; j--) {
                num += (s[j]-'0') * pow(2, k);
                if(s[j] == '1') mp[num].push({ j, i });
                else if(num == 0) mp[num].push({ j, i });
                k++;
            }
            
        }
        
        vector<vector<int>> result(q);
        
        for(int i=0 ; i<q ; i++) {
            int num = queries[i][0] xor queries[i][1];
            
            if(mp.find(num) != mp.end()) {
                auto it = mp[num].top();
                result[i] = { it.first, it.second };
            }
            else result[i] = { -1, -1 };
            
        }
        
        return result;
    }
};