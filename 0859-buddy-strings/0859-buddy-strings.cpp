class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int n = s.length();
        int m = goal.length();
        if(n != m || n == 1) return false;
        if(s == goal) {
            unordered_set<char> st(s.begin(), s.end());
            return st.size() < m;
        }
        
        int i = 0, j = n-1;
        
        while(i < j && s[i] == goal[i]) i++;
        while(i < j && s[j] == goal[j]) j--;
        
        if(i < j) swap(s[i], s[j]);
        
        return s == goal;
    }
};