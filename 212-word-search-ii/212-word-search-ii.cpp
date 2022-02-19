class TrieNode {
  public:
    vector<TrieNode*> child;
    bool isEnd; // Is true if node represents end of a word
    
    TrieNode() {
        isEnd = false;
        child = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
    TrieNode* root;
    
  public:
    TrieNode* getRoot() {
        return root;
    }
    
    Trie(vector<string>& words) {
        root = new TrieNode();
        
        for(int i=0 ; i<words.size() ; i++) {
            insertWord(words[i]);
        }
    }
    
    void insertWord(const string& word) {
        
        TrieNode* current = root;
        
        for(int i=0 ; i<word.length() ; i++) {
            int index = word[i] - 'a';
            if(current->child[index] == NULL) {
                current->child[index] = new TrieNode();
            }
            current = current->child[index];
        }
        
        current->isEnd = true;
    }
        
};

class Solution {
    void searchWord(TrieNode* root, vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, string word, unordered_set<string>& res, int n, int m) {
        
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j]) return;
        
        if(root->child[board[i][j] - 'a'] != NULL) {
            
            word += board[i][j];
            root = root->child[board[i][j] - 'a'];
            if(root->isEnd) res.insert(word);

            visited[i][j] = true;
            
            // Recursively search remaining characters of word in trie for all adjacent cells of board
            searchWord(root, board, i+1, j, visited, word, res, n, m);
            searchWord(root, board, i, j+1, visited, word, res, n, m);
            searchWord(root, board, i-1, j, visited, word, res, n, m);
            searchWord(root, board, i, j-1, visited, word, res, n, m);
            
            visited[i][j] = false; // Backtrack
        }
        
        
    }
    
    void find(vector<vector<char>>& board, unordered_set<string> s, vector<vector<bool> > visited, string str, vector<string>& result, int row, int col, int n, int m) {
        
        if(row<0 || col<0 || row>=n || col>=m || visited[row][col]) return;
        
        visited[row][col] = true;
        str += board[row][col];
        
        if(s.find(str) != s.end()) {
            result.push_back(str);
        }
        
        find(board, s, visited, str, result, row+1, col, n, m);
        find(board, s, visited, str, result, row, col+1, n, m);
        find(board, s, visited, str, result, row-1, col, n, m);
        find(board, s, visited, str, result, row, col-1, n, m);
        
        // Backtrack
        str.pop_back();
        visited[row][col] = false;
        
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int n = board.size();
        int m = board[0].size();
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        unordered_set<string> res;
        vector<string> result;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                searchWord(root, board, i, j, visited, "", res, n, m);
            }
        }
        
        for(auto it=res.begin() ; it!=res.end() ; it++) {
            result.push_back(*it);
        }
        
        return result;
        
        
//         // DFS Approach:
//         unordered_set<string> s;
//         for(int i=0 ; i<words.size() ; i++) {
//             s.insert(words[i]);
//         }
        
//         vector<vector<bool> > visited(n, vector<bool>(m, false));
//         string str = "";
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<m ; j++) {
//                 find(board, s, visited, str, result, i, j, n, m);
//             }
//         }
        
//         sort(result.begin(), result.end());
//         result.erase(unique(result.begin(), result.end()), result.end());
//         return result;
    }
};