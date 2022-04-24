class Solution {
    
    // Find parent function
    int find(char x, unordered_map<char, char>& parent) {
        
        if(parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
        
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        
        // Mapping each character with itself, means assigning each character parent of itself.
        unordered_map<char, char> parent;
        
        for(auto eq : equations) {
            parent[eq[0]] = eq[0];
            parent[eq[3]] = eq[3];
        }
        
        // Idea here is if 2 character are equal, we are grouping them together by assigning the 
        // left side character as parent of right side character.
        for(auto it : equations) {
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            
            if(it[1] == '=') parent[y] = x; // Union
        }
        
        // Now here we are simply doing is that we are checking if some characters are not equal to 
        // other but their parents are same, that means that is an imposter equation.
        for(auto it : equations) {
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            
            if(it[1] == '!' && x == y) return false;
        }
        
        return true;
    }
};