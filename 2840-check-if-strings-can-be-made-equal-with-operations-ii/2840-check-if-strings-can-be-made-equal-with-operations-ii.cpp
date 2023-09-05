class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        int n = s1.length();
        if(n == 1) return s1 == s2;
        if(s1 == s2) return true;
        
        unordered_map<char, int> mOdd, mEven;
        
        for(int i=0 ; i<n ; i++) {
            if(i % 2 == 0) {
                mEven[s1[i]]++;
                mEven[s2[i]]--;
            }
            else {
                mOdd[s1[i]]++;
                mOdd[s2[i]]--;
            }
        }
        
        for(int i=0 ; i<26 ; i++) {
            if(mEven['a'+i] != 0 || mOdd['a'+i] != 0) return false;
        }
        
        return true;
    }
};