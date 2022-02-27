class Solution {
public:
    string frequencySort(string s) {
        
        int n = s.length();
        unordered_map<char, int> m;
        
        for(int i=0 ; i<n ; i++) {
            m[s[i]]++;
        }
        
        priority_queue<pair<int, char>> p;
        
        for(auto it=m.begin() ; it!=m.end() ; it++) {
            p.push({ it->second, it->first });
        }
        
        string result = "";
        
        while(!p.empty()) {
            int n = p.top().first;
            
            while(n--) {
                result += p.top().second;
            }
            
            p.pop();
        }
        
        return result;
    }
};