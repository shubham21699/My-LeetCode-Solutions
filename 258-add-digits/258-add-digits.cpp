class Solution {
public:
    int addDigits(int num) {
        
        if(num < 10) return num;
        else if(num % 9 == 0) return 9;
        else return num % 9;
        
//         OR:
//         if(num < 10) return num;
        
//         while(num >= 10) {
//             int x = 0;
            
//             while(num) {
//                 x += num%10;
//                 num /= 10;
//             }
            
//             num = x;
//         }
        
//         return num;
    }
};