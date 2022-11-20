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
    void Inorder(TreeNode* root, vector<int>& order, unordered_map<int, int>& mp) {
        
        if(!root) return;
        
        Inorder(root->left, order, mp);
        
        mp[root->val]++;
        order.push_back(root->val);
        
        Inorder(root->right, order, mp);
        
    }
    
    int findInd(vector<int>& order, int n, int x) {
        
        int left = 0;
        int right = n-1;
        
        while(left < right) {
            
            int mid = left + (right - left) / 2;
            
            if(order[mid] < x) left = mid+1;
            else right = mid-1;
            
        }
        
        return left;
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        unordered_map<int, int> mp;
        vector<int> order;
        Inorder(root, order, mp);
        
        int n = order.size();
        int q = queries.size();
        vector<vector<int>> result;
        
        for(int i=0 ; i<q ; i++) {
            
            if(mp.find(queries[i]) != mp.end()) {
                result.push_back({ queries[i], queries[i] });
            }
            else {
                
                int ind = findInd(order, n, queries[i]);
                if(ind == 0) {
                    if(order[ind] < queries[i] && queries[i] < order[ind+1]) {
                        result.push_back({ order[ind], order[ind+1] });
                    }
                    else result.push_back({ -1, order[0] });
                }
                else if(ind == n-1) {
                    if(order[ind-1] < queries[i] && queries[i] < order[ind]) {
                        result.push_back({ order[ind-1], order[ind] });
                    }
                    else result.push_back({ order[n-1], -1 });
                }
                else {
                    if(order[ind] < queries[i] && queries[i] < order[ind+1]) {
                        result.push_back({ order[ind], order[ind+1] });
                    }
                    else if(order[ind-1] < queries[i] && queries[i] < order[ind]) {
                        result.push_back({ order[ind-1], order[ind] });
                    }
                }
                
            }
            
        }
        
        return result;
    }
};