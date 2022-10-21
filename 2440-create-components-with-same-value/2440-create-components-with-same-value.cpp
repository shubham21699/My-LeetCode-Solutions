class Solution {
public:
    int check(vector<int> graph[], vector<int>& nums, vector<int>& v, int currNode, int targetSum) {
        
        v[currNode] = nums[currNode];
        
        for(auto nextNode : graph[currNode]) {
            
            if(v[nextNode]) continue; // Already visited
            
            v[currNode] += check(graph, nums, v, nextNode, targetSum);
            
            // If v[currNode] > targetSum means that we fail the separation.
            // In this condition, we just return a very large integer.
            if(v[currNode] > targetSum) return 1e7;
            
        }
        
        if(v[currNode] == targetSum) return 0;
        return v[currNode];
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n = nums.size();
        int m = edges.size();
        vector<int> graph[n];
        
        for(int i=0 ; i<m ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        int sum = 0;
        for(int i=0 ; i<n ; i++) {
            sum += nums[i];
        }
        
        for(int j=n ; j>1 ; j--) {
            
            // Means cannot be splitted into 'j' parts
            if(sum % j != 0) continue;
            
            vector<int> v(n);
            if(check(graph, nums, v, 0, sum/j) == 0) return j-1;
            
        }
        
        return 0; // No partition poosible
    }
};