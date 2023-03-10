class Solution {
public:
    int passThePillow(int n, int time) {
        
        if(time < n) return time+1;
        if(time == n) return n-1;
        
        return n - abs(n-1 - time % (2*n - 2));
        
//         // OR:
//         int direction = 1;
//         int i = 1;
        
//         while(time--) {
//             if(direction == 1) {
//                 if(i == n) {
//                     i--;
//                     direction = -1;
//                 }
//                 else i++;
//             }
//             else if(direction == -1) {
//                 if(i == 1) {
//                     i++;
//                     direction = 1;
//                 }
//                 else i--;
//             }
//         }
        
//         return i;
    }
};