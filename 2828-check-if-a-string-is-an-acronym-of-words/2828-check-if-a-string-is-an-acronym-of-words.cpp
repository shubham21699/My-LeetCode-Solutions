class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        
        int n = words.size();
        int m = s.length();
        if(n != m) return false;
        
        string acronym = "";
        
        for(int i=0 ; i<n ; i++) {
            acronym += words[i][0];
        }
        
        return acronym == s;
    }
};