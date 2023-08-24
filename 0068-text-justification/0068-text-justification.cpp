class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n = words.size();
        int lineno = 1;
        unordered_map<int, vector<string>> mp;
        unordered_map<int, int> spaces;
        int len = 0;
        int wordlen = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(words[i].length() + len > maxWidth) {
                spaces[lineno] = maxWidth - wordlen;
                // cout << spaces[lineno] << " ";
                lineno++;
                len = 0;
                wordlen = 0;
            }
            
            mp[lineno].push_back(words[i]);
            len += words[i].length();
            wordlen += words[i].length();
            len++; // For atleast 1 space
        }
        
        vector<string> result;
        
        for(int i=1 ; i<lineno ; i++) {
            string s = "";
            int totalSpaceToAdd = spaces[i];
            int k = mp[i].size();
            int j = 0;
            
            for(int j=0 ; j<k-1 ; j++) {
                s += mp[i][j];
                int space = totalSpaceToAdd / (k - 1);
                int extraspace =  j < (totalSpaceToAdd % (k - 1)); // It gives 1/0, 1: 1 extra space to be added
                s += string(space + extraspace, ' ');
            }
            
            s += mp[i][k-1];
            s += string(maxWidth - s.size(), ' ');
            result.push_back(s);
        }
        
        string s = "";
        for(int j=0 ; j<mp[lineno].size() ; j++) {
            s += mp[lineno][j];
            if(j != mp[lineno].size() - 1) s += ' ';
        }
        
        while(s.length() < maxWidth) s += ' ';
        
        result.push_back(s);
        
        return result;
    }
};