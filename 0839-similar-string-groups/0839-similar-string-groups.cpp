class UnionFind {
public:
    vector<int> parent, rank;
    int count;

    UnionFind(int n) : parent(n), rank(n), count(n) {
        
        for (int i=0 ; i<n ; i++) {
            parent[i] = i;
        }
        
    }

    int find(int x) {
        
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        
        return parent[x];
    }

    bool union_(int x, int y) {
        
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
        }

        parent[rootY] = rootX;

        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }

        count--;

        return true;
    }
};

class Solution {
public:
    bool isSimilar(string& x, string& y) {
        
        if(x == y) return true;
        
        int diff = 0;
        
        for(int i=0 ; i<x.length() ; i++) {
            if(x[i] != y[i]) diff++;
            if(diff > 2) return false;
        }
        
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        UnionFind uf(n);
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=i+1 ; j<n ; j++) {
                if(isSimilar(strs[i], strs[j])) uf.union_(i, j);
            }
        }
        
        return uf.count;
    }
};