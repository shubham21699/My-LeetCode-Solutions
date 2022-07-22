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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(!root) return {};
        if(!root->left && !root->right) return {{ root->val }};
         
        vector<vector<int>> res;
        map<int, map<int, vector<int>>> mp;
        
        queue<pair<TreeNode* , pair<int, int>>> q;
        q.push({ root, { 0, 0 } });
        
        while(!q.empty()) {
            
            TreeNode* curr = q.front().first;
            int x = q.front().second.first; // Row
            int y = q.front().second.second; // Column
            q.pop();
            
            mp[y][x].push_back(curr->val);
            
            if(curr->left) q.push({ curr->left, { x+1, y-1 } });
            if(curr->right) q.push({ curr->right, { x+1, y+1 } });
            
        }
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            
            vector<int> v;
            
            for(auto it2 : it->second) {
                
                sort(it2.second.begin(), it2.second.end());
                v.insert(v.end(), it2.second.begin(), it2.second.end());
                
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};