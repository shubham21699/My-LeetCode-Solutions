class Solution {
public:
    bool check(vector<int>& arr, int ind, int n, unordered_map<int, bool>& visited) {
        
        if(ind >= n || ind < 0) return false;
        if(visited.find(ind) != visited.end()) return false;
        if(arr[ind] == 0) return true;
        
        visited[ind] = true;
        return check(arr, ind-arr[ind], n, visited) || check(arr, ind+arr[ind], n, visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        if(n == 1 || arr[start] == 0) return true;
        
        unordered_map<int, bool> visited;
        return check(arr, start, n, visited);
    }
};