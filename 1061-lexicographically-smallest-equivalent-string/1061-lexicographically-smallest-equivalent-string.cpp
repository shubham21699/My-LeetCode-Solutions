class Solution {
public:
    int findParent(vector<int>& parent, int x) {
        
        if(parent[x] == -1) return x;
        return parent[x] = findParent(parent, parent[x]);
    }
    
    void Union(vector<int>& parent, int x, int y) {
        
        x = findParent(parent, x);
        y = findParent(parent, y);
        
        // Min character will be the parent of max character
        if(x != y) parent[max(x, y)] = min(x, y);
        
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int n = s1.length();
        vector<int> parent(26, -1);
        
        for(int i=0 ; i<n ; i++) {
            Union(parent, s1[i]-'a', s2[i]-'a');
        }
        
        string result = "";
        
        for(int i=0 ; i<baseStr.length() ; i++) {
            result += findParent(parent, baseStr[i]-'a')+'a';
        }
        
        return result;
    }
};