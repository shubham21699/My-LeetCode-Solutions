class Solution {
public:
    int findParent(vector<int>& parent, int x) {
        
        if(parent[x] == -1) return x;
        return parent[x] = findParent(parent, parent[x]);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        /*
        We first consider all n nodes as n separate trees. Any edge joins exactly 2 of these subtrees. 
        First of all, we need to sort edges vector based on the maximum value of vertices that it connects.
        Once sorted, we start looking at the edges one by one. At every iteration, we will connect 2 subtrees.
        Suppose the max elements in these 2 subtrees is a& b respectively and there frequency is 
        a_freq & b_freq respectively.
        
        If a==b, we have found a_freq*b_freq new paths. These paths have starting nodes in 1 subtree and ending
        nodes in the other subtree. Now we merge these two subtrees. 
        We set parent[b]=a, so a_freq=a_freq + b_freq.
        Suppose a!=b. In this case we have found no new paths. Assign parent of subtree with smaller max element
        to parent of subtree with larger max element.
        Continue this until we have covered all the edges.
        
        Why are we sorting the edges ?
        Suppose we have this structure: vals- [2,4,2] and edges- [[0,1],[0,2]]. If we don't sort in increasing
        order, we will first merge the nodes 2 & 4. This subtree will have max_element as 4 and count as 1. 
        Next we will consider the 2nd edge - [0,2]. This will now merge our previously formed subtree with 
        the node - 2. While merging, it will see that our previously formed subtree has maxelement 4. 
        Since the new node 2 has maxelement as 2, it will think that there are no new possible paths from one
        subtree to the other, but this is not true. 
        The 1st subtree has a 2 that can form a new path with this new node 2.
        Thus, we are sorting to ensure that whenever we are joining 2 subtrees, we have already taken into
        account all the possible paths starting and ending with a smaller maxelement
        */
        
        int n = vals.size();
        int m = edges.size();
        vector<int> parent(n, -1);
       
        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) {
            int x = max(vals[a[0]], vals[a[1]]);
            int y = max(vals[b[0]], vals[b[1]]);
            return x < y;
        });
        
        int result = n;
        vector<int> paths(n, 1);
        
        for(int i=0 ; i<m ; i++) {
            
            int x = findParent(parent, edges[i][0]);
            int y = findParent(parent, edges[i][1]);
            
            if(vals[x] == vals[y]) {
                parent[x] = y;
                result += paths[x] * paths[y];
                paths[y] += paths[x];
            }
            else {
                if(vals[x] > vals[y]) parent[y] = x;
                else parent[x] = y;
            }
            
        }
       
        return result;
    }
};