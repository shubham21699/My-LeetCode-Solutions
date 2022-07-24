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
    int sum = 0;
    int maxSum = 0;
    
    bool isBST(TreeNode* root, TreeNode* &prev) {
        
        if(!root) return true;
        sum += root->val;
        
        if(!isBST(root->left, prev)) return false;
        if(prev != NULL && prev->val >= root->val) return false;
        
        prev = root;
        return isBST(root->right, prev);
    }
    
    // {smallest_num, largest_num, curr_sum} of a tree
    vector<int> traverse(TreeNode* root, int& ans) {
        
        if(!root) return { INT_MAX, INT_MIN, 0 };
        
        vector<int> left(traverse(root->left, ans));
        vector<int> right(traverse(root->right, ans));
        
        // Check if tree is BST
        if(left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0]) return {};
        
        int currSum = left[2] + right[2] + root->val;
        ans = max(ans, currSum);
        
        return { min(left[0], root->val), max(right[1], root->val), currSum };
    }
    
    int maxSumBST(TreeNode* root) {
        
        if(!root) return 0;
        
        int ans(0);
        traverse(root, ans);
        
        return max(0, ans);
        
//         // OR: Will give TLE
//         sum = 0;
//         TreeNode* prev = NULL;
//         if(isBST(root, prev)) maxSum = max(maxSum, sum);
        
//         maxSumBST(root->left);
//         maxSumBST(root->right);
        
//         return maxSum;
    }
};