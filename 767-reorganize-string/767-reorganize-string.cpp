class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        if(n == 1) return s;
        if(n == 2) {
            if(s[0] == s[1]) return "";
            return s;
        }
        if(n == 3) {
            if(s[0] == s[1] && s[1] == s[2]) return "";
            if(s[0] == s[1]) swap(s[1], s[2]);
            else if(s[1] == s[2]) swap(s[0], s[1]);
            return s;
        }
        
        unordered_map<char, int> m;
        
        for(int i=0 ; i<n ; i++) {
            m[s[i]]++;
            if(m[s[i]] > ceil(n/2.0)) return "";
        }
        
        priority_queue<pair<int, char>> pq;
        
        for(auto it=m.begin() ; it!=m.end() ; it++) {
            pq.push({ it->second, it->first });
        }
        
        string result = "";
        
        while(pq.size() > 1) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            
            result += p1.second;
            result += p2.second;
            
            p1.first--;
            p2.first--;
            
            if(p1.first) pq.push(p1);
            if(p2.first) pq.push(p2);
        }
        
        if(!pq.empty()) {
            if(pq.top().first > 1) return "";
            result += pq.top().second;
        }
        
        return result;
    }
};