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
    unordered_map<int, vector<TreeNode* > > mp; // For memoization
    
    vector<TreeNode* > FBT(int n) {
        
        if(n % 2 == 0) {
            return mp[n] = {};
        }
        if(n == 1) {
            return mp[1] = { new TreeNode(0) };
        }
        
        if(mp.find(n) != mp.end()) {
            return mp[n];
        }
        
        vector<TreeNode* > result;
        
        // Incrementation by 2 will avoid redundant recursive calls for even number of nodes.
        for(int i=1 ; i<n-1 ; i+=2) {
            
            vector<TreeNode* > left = FBT(i);
            vector<TreeNode* > right = FBT(n-i-1); // 1 is reserved for root node, hence n-i-1.
            
            for(auto l : left) {
                for(auto r : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
            
        }
        
        mp[n] = result;
        return result;
    }
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        
        vector<TreeNode* > result;
        if(n%2 == 0) return result;
        
        TreeNode* root = new TreeNode(0);
        
        if(n == 1) {
            result.push_back(root);
            return result;
        }
        
        if(n == 3) {
            root->left = new TreeNode(0);
            root->right = new TreeNode(0);
            result.push_back(root);
            return result;
        }
        
        return FBT(n);
    }
};