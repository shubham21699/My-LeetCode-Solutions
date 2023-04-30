// Standard Disjoint-set data structure implementation.
class DSU {
    public:
    DSU() {
        
    }
    
    int FindParent(int x, vector<int>& root) {
        return root[x] = root[x] == x ? x : FindParent(root[x], root);
    }
    
    bool Union(int x, int y, vector<int>& root) {
        
        int rootA = FindParent(x, root), rootB = FindParent(y, root);
        
        if (rootA == rootB) {
            return false;
        }
        
        root[rootA] = root[rootB];
        return true;
    }
    
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        DSU u;
        vector<int> rootA(n + 1);
        vector<int> rootB(n + 1);
        for (int i=1 ; i<=n ; i++) {
            rootA[i] = i;
            rootB[i] = i;
        }
        
        int aliceEdges = 0, bobEdges = 0;
        int result = 0;
        
        for(int i=0 ; i<m ; i++) {
            if(edges[i][0] == 3) {
                if(u.Union(edges[i][1], edges[i][2], rootA)) {
                    aliceEdges++;
                    if(u.Union(edges[i][1], edges[i][2], rootB)) {
                        bobEdges++;
                    }
                    else result++;
                }
                else result++;
            }
        }
        
        for(int i=0 ; i<m ; i++) {
            if(edges[i][0] == 1) {
                if(u.Union(edges[i][1], edges[i][2], rootA)) aliceEdges++;
                else result++;
            }
            else if(edges[i][0] == 2) {
                if(u.Union(edges[i][1], edges[i][2], rootB)) bobEdges++;
                else result++;
            }
        }
        
        return aliceEdges == n-1 && bobEdges == n-1 ? result : -1;
    }
};