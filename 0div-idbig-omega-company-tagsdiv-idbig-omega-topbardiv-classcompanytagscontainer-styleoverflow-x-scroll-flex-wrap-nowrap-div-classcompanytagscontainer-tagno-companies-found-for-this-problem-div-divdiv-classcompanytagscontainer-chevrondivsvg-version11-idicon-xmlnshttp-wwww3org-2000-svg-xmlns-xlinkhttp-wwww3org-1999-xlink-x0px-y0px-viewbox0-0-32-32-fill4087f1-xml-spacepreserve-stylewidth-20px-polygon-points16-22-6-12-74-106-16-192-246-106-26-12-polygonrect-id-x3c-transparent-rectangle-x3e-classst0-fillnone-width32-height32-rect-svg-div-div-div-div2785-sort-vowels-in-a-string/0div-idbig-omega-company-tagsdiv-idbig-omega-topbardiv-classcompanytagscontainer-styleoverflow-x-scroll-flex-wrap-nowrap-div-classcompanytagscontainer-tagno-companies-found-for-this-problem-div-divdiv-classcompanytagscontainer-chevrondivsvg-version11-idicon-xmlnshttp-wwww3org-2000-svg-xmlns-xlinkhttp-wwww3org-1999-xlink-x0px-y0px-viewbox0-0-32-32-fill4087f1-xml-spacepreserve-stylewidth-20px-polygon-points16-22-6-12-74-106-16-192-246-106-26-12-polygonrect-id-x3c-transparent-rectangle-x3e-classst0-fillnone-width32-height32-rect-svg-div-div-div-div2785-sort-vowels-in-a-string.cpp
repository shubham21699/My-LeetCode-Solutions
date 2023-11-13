class Solution {
public:
    bool isVowel(char ch) {
        
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    
    string sortVowels(string s) {
        
        int n = s.length();
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        
        for(int i=0 ; i<n ; i++) {
            if(isVowel(s[i])) pq.push({ int(s[i]), s[i] });
        }
        
        if(pq.empty()) return s;
        
        string result = s;
        
        for(int i=0 ; i<n ; i++) {
            if(isVowel(s[i])) {
                result[i] = pq.top().second;
                pq.pop();
            }
        }
        
        return result;
    }
};