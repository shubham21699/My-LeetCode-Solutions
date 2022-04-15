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
    
    /* We will use a recursive helper function that recieves a range (within n) and returns all 
    subtrees in that range.
    We have a few cases:
        1. if start > end, which is not supposed to happen, we return a list that contains only a null.
        2. if start == end it means we reached a leaf and we will return a list containing a tree that 
        has only that node.
        3. Otherwise:
        for each option of root, we get all possible subtrees with that root for left and right children.
        Then for each possible pair of left and right we add to the result a new tree. */
    
    vector<TreeNode* > generate(int start, int end) {
        
        vector<TreeNode* > res;
        
        if(start > end) return { NULL };
        if(start == end) return { new TreeNode(start) };
        
        for(int i=start ; i<=end ; i++) {
            
            vector<TreeNode* > left = generate(start, i-1);
            vector<TreeNode* > right = generate(i+1, end);
            
            for(auto l : left) {
                for(auto r : right) {
                    res.push_back(new TreeNode(i, l, r));
                }
            }
            
        }
        
        return res;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode* > result = generate(1, n);
        return result;
        
    }
};