class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        int n = sentence.length();
        if(sentence[n-1] != sentence[0]) return false;
        
        for(int i=0 ; i<n-1 ; i++) {
            if(sentence[i+1] == ' ') {
                if(sentence[i] != sentence[i+2]) return false;
            }
        }
        
        return true;
    }
};