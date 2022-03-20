class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n = tops.size();
        unordered_map<int, int> m1, m2, same;
        
        for(int i=0 ; i<n ; i++) {
            m1[tops[i]]++;
            m2[bottoms[i]]++;
            
            if(tops[i] == bottoms[i]) same[tops[i]]++;
            
        }
        
        for(int i=1 ; i<=6 ; i++) {
            if((m1[i] + m2[i] - same[i]) == n) return n - max(m1[i], m2[i]);
        }
        
        return -1;
    }
};