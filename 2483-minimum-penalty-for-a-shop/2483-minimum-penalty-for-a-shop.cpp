class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.size();
        int penalty = 0;
        for(int i=0 ; i<n ; i++) {
            if(customers[i] == 'Y') penalty++;
        }
        
        int minPenalty = penalty;
        int closingTime = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(customers[i] == 'Y') penalty--;
            if(customers[i] == 'N') penalty++;
            
            if(minPenalty > penalty) {
                minPenalty = penalty;
                closingTime = i+1;
            }
        }
        
        return closingTime;
    }
};