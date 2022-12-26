class Solution {
public: 
    int closetTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();
        if(words[startIndex] == target) return 0;
        
        int steps = 1;        
        int i = (startIndex+1) % n;
        int j = (startIndex-1+n) % n;
        
        while(i != startIndex && j != startIndex) {
            if(words[i] == target || words[j] == target) return steps;
            
            i = (i+1)%n;
            j = (j-1+n)%n;
            steps++;
        }
        
        return -1;
    }
};