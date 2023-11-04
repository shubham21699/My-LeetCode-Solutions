class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        // Two different direction moving ants change directino on meet == continue moving in same direction
        // So we calculate maxDistanceTravelled by all ants in there respective direction will be the 
        // time at which the last ants fall out of plank.
        int maxDistanceTravelled = 0;
        
        for(int i=0 ; i<left.size() ; i++) {
            maxDistanceTravelled = max(maxDistanceTravelled, left[i]);
        }
        
        for(int i=0 ; i<right.size() ; i++) {
            maxDistanceTravelled = max(maxDistanceTravelled, n - right[i]);
        }
        
        return maxDistanceTravelled;
    }
};