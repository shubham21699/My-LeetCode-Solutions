/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recover(string& traversal, int& i, int n, int depth) {
        
        int nextDigitPos = i;
        while(nextDigitPos < n && traversal[nextDigitPos] == '-') {
            nextDigitPos++;
        }
        
        if(nextDigitPos - i != depth) return NULL;
        
        int num = 0;
        i = nextDigitPos;
        while(i < n && traversal[i] != '-') {
            num = num*10 + (traversal[i]-'0');
            i++;
        }
        
        TreeNode* root = new TreeNode(num);
        root->left = recover(traversal, i, n, depth+1);
        root->right = recover(traversal, i, n, depth+1);
        return root;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        
        int n = traversal.length();
        int i = 0;
        return recover(traversal, i, n, 0);
    }
};