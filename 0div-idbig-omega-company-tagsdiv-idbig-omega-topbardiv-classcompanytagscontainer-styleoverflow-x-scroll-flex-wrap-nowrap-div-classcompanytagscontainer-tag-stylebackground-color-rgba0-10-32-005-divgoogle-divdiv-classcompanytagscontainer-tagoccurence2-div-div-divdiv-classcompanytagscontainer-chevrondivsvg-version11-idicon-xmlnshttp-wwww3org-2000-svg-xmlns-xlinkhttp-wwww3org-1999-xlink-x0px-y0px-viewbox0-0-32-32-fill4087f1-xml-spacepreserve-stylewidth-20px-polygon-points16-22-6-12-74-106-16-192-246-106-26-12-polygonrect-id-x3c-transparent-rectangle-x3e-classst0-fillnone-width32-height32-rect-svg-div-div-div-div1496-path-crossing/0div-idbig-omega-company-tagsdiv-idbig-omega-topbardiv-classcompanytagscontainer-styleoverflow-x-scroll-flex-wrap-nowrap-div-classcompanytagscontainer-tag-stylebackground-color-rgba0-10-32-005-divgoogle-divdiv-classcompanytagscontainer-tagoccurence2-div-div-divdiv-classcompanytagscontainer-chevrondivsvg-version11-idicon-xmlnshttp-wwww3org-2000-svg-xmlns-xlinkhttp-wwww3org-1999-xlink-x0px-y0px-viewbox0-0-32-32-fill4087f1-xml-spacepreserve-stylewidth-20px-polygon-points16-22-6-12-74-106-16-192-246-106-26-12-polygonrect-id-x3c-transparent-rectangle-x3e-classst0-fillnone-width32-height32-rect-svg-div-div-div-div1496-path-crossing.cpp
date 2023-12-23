class Solution {
public:
    bool isPathCrossing(string path) {
        
        int n = path.length();
        set<pair<int, int>> visited;
        int x = 0, y = 0;
        visited.insert({ 0, 0 });
        
        for(int i=0 ; i<n ; i++) {
            if(path[i] == 'N') y++;
            else if(path[i] == 'S') y--;
            else if(path[i] == 'E') x++;
            else if(path[i] == 'W') x--;
            
            if(visited.find({ x, y }) != visited.end()) return true;
            visited.insert({ x, y });
        }
        
        return false;
    }
};