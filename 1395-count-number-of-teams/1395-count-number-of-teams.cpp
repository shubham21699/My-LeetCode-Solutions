class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size();
        if(n == 3) {
            if((rating[0] < rating[1] && rating[1] < rating[2]) 
               || (rating[0] > rating[1] && rating[1] > rating[2])) 
                return 1;
            return 0;
        }
        
        // O(N^2)
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            int leftSmall=0, leftLarge=0, rightSmall=0, rightLarge=0;
            
            // For Left Part
            for(int j=0 ; j<i ; j++) {
                if(rating[j] < rating[i]) leftSmall++;
                else leftLarge++;
            }
            
            // For Right Part
            for(int j=i+1 ; j<n ; j++) {
                if(rating[j] < rating[i]) rightSmall++;
                else rightLarge++;
            }
            
            count += (leftSmall * rightLarge) + (leftLarge * rightSmall);
        }
        
        return count;
        
        
//         // OR: O(N^3)
//         int count = 0;
        
//         for(int i=0 ; i<n-2 ; i++) {
//             for(int j=i+1 ; j<n-1 ; j++) {
//                 for(int k=j+1 ; k<n ; k++) {
//                     if(rating[i] < rating[j] && rating[j] < rating[k]) count++;
//                     if(rating[i] > rating[j] && rating[j] > rating[k]) count++;
//                 }
//             }
//         }
        
//         return count;
    }
};