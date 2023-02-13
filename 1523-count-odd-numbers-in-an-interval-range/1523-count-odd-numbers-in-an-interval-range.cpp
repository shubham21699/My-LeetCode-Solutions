class Solution {
public:
    int countOdds(int low, int high) {
        
        // The count of odd numbers between 1 and low-1 is low / 2
        // The count of odd numbers between 1 and high is (high + 1 ) / 2
        return (high+1)/2 - low/2;
        
//         // OR:
//         int count = 0;
        
//         while(low <= high) {
//             if(low % 2 != 0) count++;
//             low++;
//         }
        
//         return count;
    }
};