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
    TreeNode* construct(vector<int>& nums, int left, int right) {
        
        if(left > right) return NULL;
        
        int maxEle_index = left;
        for(int i=left+1 ; i<=right ; i++) {
            if(nums[i] > nums[maxEle_index]) {
                maxEle_index = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[maxEle_index]);
        root->left = construct(nums, left, maxEle_index-1);
        root->right = construct(nums, maxEle_index+1, right);
        
        return root;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) {
            TreeNode* newTree = new TreeNode(nums[0]);
            return newTree;
        }
        
        return construct(nums, 0, n-1);
    }
};