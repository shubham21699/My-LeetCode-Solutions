class Solution {
public:
    int nextGreaterElement(int n) {
        
        string s = to_string(n);
        int len = s.length();
        
        if(len == 1) return -1;
        if(len == 2) {
            if(s[0] < s[1]) {
                reverse(s.begin(), s.end());
                n = stoi(s);
                return n;
            }
            else return -1;
        }
        
        next_permutation(s.begin(), s.end());
        int result = stoll(s);
        
        return (result <= n) ? -1 : result;
    }
};