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
    void Inorder(TreeNode* root, vector<int>& inorder) {
        
        if(!root) return;
        
        Inorder(root->left, inorder);
        inorder.push_back(root->val);
        Inorder(root->right, inorder);
        
    }
    
    bool find(TreeNode* r1, TreeNode* r2) {
        
        if(!r1->left && !r1->right && !r2->left && !r2->right) return true;
        if(!r1->left->left && !r2->right->right && !r1->left->right && !r2->right->left && !r1->right->left && !r2->left->right && !r1->right->right && !r2->left->left) return true;
        
        if(!r1->left || !r1->right || !r2->left || !r2->right) return false;
        if(!r1->left->left || !r2->right->right || !r1->left->right || !r2->right->left || !r1->right->left && !r2->left->right || !r1->right->right || !r2->left->left) return false;
        if(r1->left->left != r2->right->right || r1->left->right != r2->right->left || r1->right->left != r2->left->right || r1->right->right != r2->left->left) return false;
        
        return find(r1->left, r2->right) && find(r1->right, r2->left);
        
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        if(root->left->val != root->right->val) return false;
        // if(root->left->left != root->right->right || root->left->right != root->right->left) return false;
        
        // return find(root->left, root->right);
        
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            vector<int> v;
            
            while(n--) {
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left) {
                    q.push(curr->left);
                    v.push_back(curr->left->val);
                }
                else v.push_back(0);
                
                if(curr->right) {
                    q.push(curr->right);
                    v.push_back(curr->right->val);
                }
                else v.push_back(0);
                
            }
            
            int i = 0;
            int j = v.size()-1;
            
            while(i < j) {
                if(v[i] != v[j]) return false;
                i++;
                j--;
            }
            
        }
        
        return true;
        
        
//         vector<int> inorder;
//         Inorder(root, inorder);
        
//         int i = 0;
//         int j = inorder.size()-1;
        
//         while(i < j) {
//             if(inorder[i] != inorder[j]) return false;
//             i++;
//             j--;
//         }
        
//         return true;
    }
};