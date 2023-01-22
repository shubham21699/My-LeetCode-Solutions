class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        int n = s.length();
        if(s == target) return true;
        
        bool count1inS = false, count1inT = false;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '1') count1inS = true;
            if(target[i] == '1') count1inT = true;
        }
        
        return count1inS == count1inT;
    }
};