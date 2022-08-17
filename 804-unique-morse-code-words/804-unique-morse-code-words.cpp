class Solution {
public:
    unordered_map<char, string> mp = {
        {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, 
        {'f', "..-."}, {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"}, 
        {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."}, {'o', "---"}, 
        {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, 
        {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}
    };
    
    int uniqueMorseRepresentations(vector<string>& words) {
        
        int n = words.size();
        if(n == 1) return 1;
        
        unordered_set<string> st;
        
        for(int i=0 ; i<n ; i++) {
            string res = "";
            
            for(int j=0 ; j<words[i].length() ; j++) {
                res += mp[words[i][j]];
            }
            
            st.insert(res);
        }
     
        return st.size();
    }
};