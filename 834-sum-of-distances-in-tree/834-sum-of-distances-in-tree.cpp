class Solution {
public:
    /*
    # First DFS
         [TREE] |      [COUNT]     [RET]
            0   |       10          [ ] = (1+0) + (7+10) +(1+0)  = 19      
          / | \ |      / | \       / | \ 
         1  2  3|     1  7  1     0  10 0       <--- ret[root] = sum(count[child])+sum(count[child])
           /|\  |       /|\         /|\              sum(count[child]) = travel again「count[child]」many times of path root->child 
          4 5 6 |      4 1 1       4 0 0             sum(count[child]) = prev traveled paths sum
         /|     |     /|          /|   
        7 8     |    1 2         0 1    
         /      |     /           /         
        9       |    1           0           
        
   # Second DFS           
         [RET]  |                  |                  
            19  |           19     |       19             
          / | \ |          / | \   |      / | \ 
         0  10 0| [19-1+10-1] 10 0 |  28 [19-7+10-7] 0       <---  = parent.ret - root.count + (N - root.count)*1 
           /|\  |           /|\    |       /|\                      
          4 0 0 |          4 0 0   |      4 0 0                Every node other than it's subtree node: become 1 step more far away
         /|     |         /|       |     /|   
        0 1     |        0 1       |    0 1    
         /      |         /        |     /         
        0       |        0         |    0         
        
    # Ans = [19,27,15,27,17,23,23,25,23,31] 
    
    -------------- Example --------------------------------------------    
        
        Count         Ret         Dfs update ret...
          6            8            8              8     
         / \          / \          /  \           / \
        1   4        0   3    [8-1+N-1] 3       12   6
           /|\          /|\          /|\            /|\
          1 1 1        0 0 0        0 0 0        10 10 [6-1+N-1]   N=6
    */
    
    void postOrderDFS(vector<int> graph[], vector<int>& count, vector<int>& res, int root, int prevNode) {
        
        for(auto node : graph[root]) {
            
            if(node == prevNode) continue;
            postOrderDFS(graph, count, res, node, root);
            
            count[root] += count[node];
            res[root] += res[node] + count[node];
            
        }
        
    }
    
    void preOrderDFS(vector<int> graph[], vector<int>& count, vector<int>& res, int root, int prevNode) {
        
        for(auto node : graph[root]) {
            
            if(node == prevNode) continue;
            
            res[node] = res[root] - count[node] + count.size() - count[node]; 
            preOrderDFS(graph, count, res, node, root);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return { 0 };
        
        vector<int> graph[n];
        for(int i=0 ; i<edges.size() ; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> count(n, 1); // count[i] counts all nodes in the subtree i
        vector<int> res(n, 0); // res[i] counts sum of distance in subtree i
        
        postOrderDFS(graph, count, res, 0, -1);
        preOrderDFS(graph, count, res, 0, -1);
        
        return res;
    }
};