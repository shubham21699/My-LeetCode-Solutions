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
    int minimumOperations(TreeNode* root) {
        
        if(!root) return 0;
        if(!root->left && !root->right) return 0;
        
        queue<TreeNode* > q;
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
        
        int steps = 0;
        
        while(!q.empty()) {
            
            int n = q.size();
            vector<int> nums;
            
            while(n--) {
                
                auto curr = q.front();
                q.pop();
                
                nums.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
            }
            
            int len = nums.size();
            map<int, int> map;
            
            for (int i=0; i<len; i++) map[nums[i]] = i;

            sort(nums.begin(), nums.end());

            // To keep track of visited elements. Initialize all elements as not visited or false.
            vector<bool> visited(len, false);

            for (int i=0; i<len; i++) {

                // already swapped and corrected or already present at correct position
                if (visited[i] || map[nums[i]] == i)
                    continue;

                int j = i, cycle_size = 0;
                
                while (!visited[j]) {
                    visited[j] = true;

                    // move to next node
                    j = map[nums[j]];
                    cycle_size++;
                }

                // Update answer by adding current cycle.
                if (cycle_size > 0) {
                    steps += (cycle_size - 1);
                }
            }
            
        }
        
        return steps;
    }
};