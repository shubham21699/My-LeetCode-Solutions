class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        int n = words.size();
        int countPairs = 0;
        
        for(int i=0 ; i<n ; i++) {
            set<char> st1(words[i].begin(), words[i].end());
            for(int j=i+1 ; j<n ; j++) {
                set<char> st2(words[j].begin(), words[j].end());
                
                if(st1 == st2) countPairs++;
            }
        }
        
        return countPairs;
    }
};