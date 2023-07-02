class Solution {
public:
    void check(vector<vector<int>>& requests, int index, int n, vector<int>& inDegree, int count, int& ans) {
        
        if(index == requests.size()) {
            for(int i=0 ; i<n ; i++) {
                if(inDegree[i] != 0) return;
            }
            
            ans = max(ans, count);
            return;
        }
        
        // Take
        inDegree[requests[index][0]]--;
        inDegree[requests[index][1]]++;
        check(requests, index+1, n, inDegree, count+1, ans);
        
        // Not Take
        inDegree[requests[index][0]]++;
        inDegree[requests[index][1]]--;
        check(requests, index+1, n, inDegree, count, ans);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> inDegree(n, 0);
        int ans = 0;
        
        check(requests, 0, n, inDegree, 0, ans);
        return ans;
    }
};