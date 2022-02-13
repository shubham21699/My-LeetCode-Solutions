class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        
        if(s[0] == '0') return 0;
        if(n == 1) return 1;
        
        vector<int> ways(n+1, 0);
        ways[n] = 1;
        
        for(int index=n-1 ; index>=0 ; index--) {
            if(s[index] == '0') ways[index] = 0;
            else if(index<n-1 && (s[index] == '1' && s[index+1] >='0' && s[index+1] <= '9') || (s[index] == '2' && s[index+1] >= '0' && s[index+1] <= '6')) {
                ways[index] = ways[index+1] + ways[index+2];
            }
            else ways[index] = ways[index+1];
        }
        
        return ways[0];
    }
};