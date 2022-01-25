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
    bool check(TreeNode* root, TreeNode* &prev) {
        if(!root) return true;
        
        if(!check(root->left, prev)) return false;
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        return check(root->right, prev);
    }
    
    void Inorder(TreeNode* root, vector<int>& inorder) {
        if(!root) return;
        
        Inorder(root->left, inorder);
        inorder.push_back(root->val);
        Inorder(root->right, inorder);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        TreeNode* prev = NULL;
        return check(root, prev);
        
//         OR:
//         vector<int> inorder;
//         Inorder(root, inorder);
        
//         for(int i=0 ; i<inorder.size()-1 ; i++) {
//             if(inorder[i] >= inorder[i+1]) return false;
//         }
        
//         return true;
    }
};