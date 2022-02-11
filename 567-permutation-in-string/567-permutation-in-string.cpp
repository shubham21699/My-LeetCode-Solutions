class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        
        unordered_map<char, int> m1, m2;
        int index = 0;
        
        for(int i=0 ; i<n ; i++) m1[s1[i]]++;
        
        for(int i=0 ; i<m ; i++) {
            
            m2[s2[i]]++;
            
            // If current window size equals to s1 string, then check if both hashmaps are same or not.
            if(i-index+1 == n) {
                if(m2 == m1) return true;
                
                m2[s2[index]] == 1 ? m2.erase(s2[index]) : m2[s2[index]]--;
                index++;
            }
            
        }
        
        return false;
        
        
//         OR: Will give TLE
//         sort(s1.begin(), s1.end());
        
//         for(int i=0 ; i<=m-n ; i++) {
//             string x = s2.substr(i, n);
//             sort(x.begin(), x.end());
//             if(x == s1) return true;
//         }
        
//         return false;
    }
};