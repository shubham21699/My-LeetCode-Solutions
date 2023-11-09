class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        // We first compute how many minutes each monster needs to reach the city, based on the initial
        // position and speed.
        // Then, we sort our monsters by their arrival time.
        // Finally, we shoot monsters (in the arrival order), until a monster arrives earlier than we can
        // make our next shot. 
        // For example, if we have made 5 shots, and the next monster arrives in 4 minutes, we lose.
        
        int n = dist.size();
        
        for(int i=0 ; i<n ; i++) {
            dist[i] = (dist[i] - 1) / speed[i];
        }
        
        sort(dist.begin(), dist.end());
        
        for(int i=0 ; i<n ; i++) {
            if(dist[i] < i) return i;
        }
        
        return n;
    }
};