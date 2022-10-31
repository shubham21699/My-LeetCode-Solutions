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
//     // Calculating height without considering subtree having it's root value of queries[i] value
//     int htAfterRem(TreeNode* root, int nodeVal) {
        
//         if(!root || root->val == nodeVal) return 0;
        
//         return 1 + max(htAfterRem(root->left, nodeVal), htAfterRem(root->right, nodeVal));
//     }
    
    unordered_map<int, int> startTime, endTime, depth;
    int time = 0;
    
    void traverse(TreeNode* root, int d) {
        
        startTime[root->val] = ++time;
        depth[startTime[root->val]] = d;
        
        if(root->left) traverse(root->left, d+1);
        if(root->right) traverse(root->right, d+1);
     
        endTime[root->val] = time;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        
        int m = queries.size();
        vector<int> result(m, 0);
        
        traverse(root, 0);
        int n = depth.size(); // No. of nodes
        
        vector<int> maxPrefDepth(n+2), maxSuffDepth(n+2);
      
        for(int i=1 ; i<=n ; i++) maxPrefDepth[i] = max(maxPrefDepth[i-1], depth[i]);
        for(int i=n ; i>=0 ; i--) maxSuffDepth[i] = max(maxSuffDepth[i+1], depth[i]);
        
        for(int i=0 ; i<m ; i++) {
            int startT = startTime[queries[i]] - 1;
            int endT = endTime[queries[i]] + 1;
            
            result[i] = max(maxPrefDepth[startT], maxSuffDepth[endT]);
        }
        
        return result;
        
        
//         // OR: Brute Force
//         for(int i=0 ; i<m ; i++) {
//             int ht = htAfterRem(root, queries[i]);
//             result[i] = ht-1;
//         }
        
//         return result;
    }
};