class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int n = moves.length();
        int dist = 0;
        int lrdist = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(moves[i] == 'L') lrdist--;
            else if(moves[i] == 'R') lrdist++;
            else dist++;
        }
        
        return abs(lrdist) + dist;
    }
};