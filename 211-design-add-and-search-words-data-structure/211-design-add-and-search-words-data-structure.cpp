class TrieNode {
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }  
};

class WordDictionary {
    TrieNode* root = new TrieNode();
    
    bool Search(const char* word, TrieNode* node) {
        
        for(int i=0 ; word[i] && node ; i++) {
            if(word[i] != '.') {
                node = node->children[word[i] - 'a'];
            }
            else {
                TrieNode* temp = node;
                for(int j=0 ; j<26 ; j++) {
                    node = temp->children[j];
                    if(Search(word + i + 1, node)) return true;
                }
            }
        }
        
        return node && node->word;
    }
    
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        
        TrieNode* node = root;
        
        for(char c : word) {
            if(!node->children[c-'a']) {
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        
        node->word = true;
    }
    
    bool search(string word) {
        return Search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */