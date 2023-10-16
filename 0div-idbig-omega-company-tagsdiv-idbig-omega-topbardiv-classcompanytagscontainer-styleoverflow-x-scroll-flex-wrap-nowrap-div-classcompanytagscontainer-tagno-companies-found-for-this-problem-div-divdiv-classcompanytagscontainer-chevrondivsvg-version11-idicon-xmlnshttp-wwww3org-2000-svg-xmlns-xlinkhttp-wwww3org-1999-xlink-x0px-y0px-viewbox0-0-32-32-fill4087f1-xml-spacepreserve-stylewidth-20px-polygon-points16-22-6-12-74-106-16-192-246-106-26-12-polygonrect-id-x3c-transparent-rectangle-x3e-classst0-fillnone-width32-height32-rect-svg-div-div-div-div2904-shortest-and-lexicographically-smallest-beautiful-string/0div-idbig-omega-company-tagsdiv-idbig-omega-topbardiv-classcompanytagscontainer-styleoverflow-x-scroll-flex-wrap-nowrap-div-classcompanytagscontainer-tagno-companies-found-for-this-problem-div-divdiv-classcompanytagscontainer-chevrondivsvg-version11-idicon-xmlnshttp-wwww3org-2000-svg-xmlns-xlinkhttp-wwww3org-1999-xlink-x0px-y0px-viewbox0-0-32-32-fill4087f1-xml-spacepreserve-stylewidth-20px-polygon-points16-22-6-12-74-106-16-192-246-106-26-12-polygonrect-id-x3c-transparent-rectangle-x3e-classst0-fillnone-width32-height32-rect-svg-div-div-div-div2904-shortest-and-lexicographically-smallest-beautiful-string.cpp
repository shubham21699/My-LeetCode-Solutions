class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.length();
        if(n < k) return "";
        
        int t = 0;
        while(t < n && s[t] == '0') t++;
        
        if(t == n) return "";
        
        string result = s;
        int j = t;
        int count1 = 0;
        int total1 = 0;
        
        for(int i=t ; i<n ; i++) {
            
            if(s[i] == '1') count1++, total1++;
            
            if(count1 == k) {
                string x = s.substr(j, i-j+1);
                
                if(i-j+1 < result.length()) result = x;
                else if(i-j+1 == result.length() && string(x) < string(result)) result = x;
                
                count1--;
                j++;
                
                while(j<n && s[j] != '1') j++;
            }
            
        }
        
        return total1 < k ? "" : result;
    }
};