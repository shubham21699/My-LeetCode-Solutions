class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> parChild, graph; // parChild is parent - child edge in our DFS
    vector<vector<bool>> childs; // 2D array to store that i ia a parent of j
    vector<int> childXOR, nums, par; // childXOR to store result of XORs of child node and par is a gobal array to track the parents of node in DFS
    
    int dfs(int i) {
        
        int ans = nums[i];
        visited[i] = true;
        
        for(int p : par) {
            // Defining this node as the child of all its parents
            childs[p][i] = true;
        }
        
        par.push_back(i);
        
        for(auto child : graph[i]) {
            if(!visited[child]) {
                parChild.push_back({ i, child });
                ans ^= dfs(child); // Recursively calculting XORs
            }
        }
        
        par.pop_back();
        return childXOR[i] = ans;
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n = nums.size();
        int result = INT_MAX;
        visited = vector<bool>(n);
        parChild = vector<vector<int>>();
        graph = vector<vector<int>>(n);
        childXOR = vector<int>(n);
        childs = vector<vector<bool>>(n, vector<bool>(n));
        this->nums = nums;
        par = vector<int>();
        
        for(int i=0 ; i<edges.size() ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(0);
        
        for(int i=0 ; i<parChild.size() ; i++) {
            for(int j=i+1 ; j<parChild.size() ; j++) { // Removing an edge i and j
                // Node that will come below when you delete an edge i and j
                int a = parChild[i][1];
                int b = parChild[j][1];
                
                int xa = childXOR[a];
                int xb = childXOR[b];
                int xc = childXOR[0];
                
                if(childs[a][b]) xc ^= xa, xa ^= xb;
                else xc ^= xa, xc ^= xb;
                
                result = min(result, max({ xa, xb, xc }) - min({ xa, xb, xc }));
            }
        }

        return result;
    }
};