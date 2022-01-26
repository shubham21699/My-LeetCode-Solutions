class Solution {
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length()-1;
        
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void find(vector<vector<string> >& result, vector<string>& v, string s, int index, int n) {
        
        if(index >= n) {
            result.push_back(v);
            return;
        }
        
        for(int i=index ; i<n ; i++) {
            string x = s.substr(index, i-index+1);
            
            if(isPalindrome(x)) {
                v.push_back(x);
                find(result, v, s, i+1, n);
                v.pop_back();
            }
            
        }
        
    }
    
public:
    vector<vector<string>> partition(string s) {
        
        int n = s.length();
        vector<vector<string> > result;
        vector<string> v;
        
        if(n == 0) return result;
        if(n == 1) {
            result.push_back({ s });
            return result;
        }
        
        find(result, v, s, 0, n);
        return result;
    }
};