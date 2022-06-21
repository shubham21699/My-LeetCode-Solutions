/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* buildTree(vector<vector<int>>& grid, int i, int j, int length) {
        
        if(length == 1) {
            return new Node(grid[i][j] == 1, true, NULL, NULL, NULL, NULL);
        }
        
        int newLen = length/2;
        Node* topLeft = buildTree(grid, i, j, newLen);
        Node* topRight = buildTree(grid, i, j + newLen, newLen);
        Node* bottomLeft = buildTree(grid, i + newLen, j, newLen);
        Node* bottomRight = buildTree(grid, i + newLen, j + newLen, newLen);
        
        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && 
          (( topLeft->val && topRight->val && bottomLeft->val && bottomRight->val ) || 
          !( topLeft->val || topRight->val || bottomLeft->val || bottomRight->val ))) {
            
            bool val = topLeft->val;
            delete topLeft;
            topLeft = NULL;
            
            delete topRight;
            topRight = NULL;
            
            delete bottomLeft;
            bottomLeft = NULL;
            
            delete bottomRight;
            bottomRight = NULL;
            
            return new Node(val, true, NULL, NULL, NULL, NULL);
        }
        
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n == 0) return NULL;
        
        return buildTree(grid, 0, 0, n);
    }
};