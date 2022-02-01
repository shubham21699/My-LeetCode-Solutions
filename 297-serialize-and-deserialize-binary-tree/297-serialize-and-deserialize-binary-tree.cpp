/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode* deserialize_queue(queue<string>& q) {
        
        string s = q.front();
        q.pop();
        
        if(s == "NULL") return NULL;
        
        TreeNode* root = new TreeNode(stoi(s));
        root->left = deserialize_queue(q);
        root->right = deserialize_queue(q);
        
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(!root) return "NULL";
        
        // Serialize it in Preorder form.
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int n = data.size();
        if(data == "NULL") return NULL;
        
        queue<string> q;
        string s = "";
        
        for(int i=0 ; i<n ; i++) {
            
            if(data[i] == ',') {
                q.push(s);
                s = "";
                continue;
            }
            
            s += data[i];
            
        }
        
        if(s.length()) q.push(s);
        return deserialize_queue(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));