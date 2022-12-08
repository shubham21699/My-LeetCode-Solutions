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
    void Traverse(TreeNode* root, vector<int>& order) {

        if(!root) return;
        if(!root->left && !root->right) {
            order.push_back(root->val);
            return;
        }

        Traverse(root->left, order);
        Traverse(root->right, order);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> leafOrder1, leafOrder2;

        Traverse(root1, leafOrder1);
        Traverse(root2, leafOrder2);
        
        return leafOrder1 == leafOrder2;
    }
};