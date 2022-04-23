class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        if(n == 1) return true;
        
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            
            int currentRoomNo = q.front();
            visited.insert(currentRoomNo);
            q.pop();
            
            for(auto key : rooms[currentRoomNo]) {
                if(visited.find(key) == visited.end()) {
                    q.push(key);
                }
            }
            
        }
        
        return visited.size()==n;
    }
};