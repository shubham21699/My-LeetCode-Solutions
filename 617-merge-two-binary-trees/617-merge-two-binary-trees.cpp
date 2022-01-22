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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
                
        TreeNode* result = new TreeNode();
        
        if(root1 && root2) result->val = root1->val + root2->val;
        else if(root1) return root1;
        else if(root2) return root2;
        else return NULL;
        
        if(root1->left && root2->left) result->left = mergeTrees(root1->left, root2->left);
        else if(root1->left) result->left = root1->left;
        else if(root2->left) result->left = root2->left;
        else result->left = NULL;
        
        if(root1->right && root2->right) result->right = mergeTrees(root1->right, root2->right);
        else if(root1->right) result->right = root1->right;
        else if(root2->right) result->right = root2->right;
        else result->right = NULL;
        
        return result;
    }
};