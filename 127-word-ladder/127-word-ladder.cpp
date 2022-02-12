class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ladder = 1;
        
        while(!q.empty()) {
            
            int n = q.size();
            
            while(n--) {
                
                string word = q.front();
                q.pop();
                
                if(word == endWord) return ladder;
                
                dict.erase(word);
                
                for(int i=0 ; i<word.length() ; i++) {
                    char c = word[i];
                    
                    for(int j=0 ; j<26 ; j++) {
                        word[i] = 'a' + j;
                        
                        if(dict.find(word) != dict.end()) {
                            q.push(word);
                        }
                    }
                    
                    word[i] = c;
                }
                
            }
            
            ladder++;
        }
        
        // If no sequence exists
        return 0;
    }
};