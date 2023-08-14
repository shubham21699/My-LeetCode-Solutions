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
    void traversedel(TreeNode*& root, unordered_set<int>& st, unordered_map<TreeNode*, TreeNode*>& parent, vector<TreeNode*>& result) {
        
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        
        traversedel(root->left, st, parent, result);
        traversedel(root->right, st, parent, result);
        
        if(st.find(root->val) != st.end()) {
            TreeNode* pr = parent[root];
            TreeNode* prl = root->left;
            TreeNode* prr = root->right;
            
            if(!pr) root = NULL; // If root has to be deleted, make root as NULL
            if(pr && pr->left && pr->left == root) pr->left = NULL;
            if(pr && pr->right && pr->right == root) pr->right = NULL;
            if(prl) result.push_back(prl);
            if(prr) result.push_back(prr);
        }
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        if(to_delete.size() == 0) return { root };
        
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> result;
        
        traversedel(root, st, parent, result);
        if(root) result.push_back(root); // Push the root tree after deleting rest nodes and root is not deleted
        return result;
    }
};