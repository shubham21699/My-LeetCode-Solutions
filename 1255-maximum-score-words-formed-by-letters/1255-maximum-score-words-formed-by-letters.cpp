class Solution {
public:
    int maxScore(vector<string>& words, int i, int n, vector<int>& score, unordered_map<char, int>& freq) {
        
        if(i >= n) return 0;
        int skipCurr = maxScore(words, i+1, n, score, freq);
        int sc = 0;
        bool formed = true;
        unordered_map<char, int> freq1 = freq;
        
        for(int j=0 ; j<words[i].length() ; j++) {
            if(freq1[words[i][j]] > 0) {
                sc += score[words[i][j] - 'a'];
                freq1[words[i][j]]--;
            }
            else {
                formed = false;
                break;
            }
        }
        
        return max(skipCurr, formed ? sc + maxScore(words, i+1, n, score, freq1) : 0);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n = words.size();
        int m = letters.size();
        
        unordered_map<char, int> freq;
        for(int i=0 ; i<m ; i++) freq[letters[i]]++;
        
        return maxScore(words, 0, n, score, freq);
    }
};