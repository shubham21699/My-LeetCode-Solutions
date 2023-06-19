class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int n = gain.size();
        int largest = max(0, gain[0]);
        
        for(int i=1 ; i<n ; i++) {
            gain[i] += gain[i-1];
            largest = max(largest, gain[i]);
        }
        
        return largest;
    }
};