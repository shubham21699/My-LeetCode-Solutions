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
class BSTIterator {
    vector<int> inorder;
    int index = 0;
    int n = 0;
    
    void Inorder(TreeNode* root) {
        
        if(!root) return;
        
        Inorder(root->left);
        inorder.push_back(root->val);
        Inorder(root->right);
        
    }
    
public:
    BSTIterator(TreeNode* root) {
        
        inorder.clear();
        Inorder(root);
        index = 0;
        n = inorder.size();
        
    }
    
    int next() {
        
        return inorder[index++];
        
    }
    
    bool hasNext() {
        
        return index < n;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */