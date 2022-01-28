/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool pathToTarget(TreeNode* root, vector<TreeNode* >& v, TreeNode* target) {
        
        // If root is NULL, there is no path
        if(!root) return false;
        v.push_back(root);
        
        // If this is required node, return true
        if(root->val == target->val) return true;
        
        // Else check if required node lies in left subtree or right subtree
        if(pathToTarget(root->left, v, target) || pathToTarget(root->right, v, target)) return true;
        
        // Required node doesn't lie in left subtree or right subtree of current node, 
        // then remove current node from path array and return false
        v.pop_back();
        return false;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode* > vp, vq;
        pathToTarget(root, vp, p);
        pathToTarget(root, vq, q);
        
        unordered_set<TreeNode* > st;
        for(int i=0 ; i<vp.size() ; i++) st.insert(vp[i]);
        
        TreeNode* result = NULL;
        
        // Start iterating from last and break when same ancestor found because LCA is the 
        // one common in both from last
        for(int j=vq.size()-1 ; j>=0 ; j--) {
            if(st.find(vq[j]) != st.end()) {
                result = vq[j];
                break;
            }
        }
        
        return result;
    }
};