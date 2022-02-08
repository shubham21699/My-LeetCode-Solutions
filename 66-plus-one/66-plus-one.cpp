class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        if(n == 1) {
            if(digits[0] == 9) {
                digits[0] = 1;
                digits.push_back(0);
            }
            else digits[0] += 1;
            return digits;
        }
        
        for(int i=n-1 ; i>=0 ; i--) {
            
            if(digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i]++;
                return digits;
            }
            
        }
        
        // This case will arrive when all the digits are 9 
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
        
//         OR:
//         reverse(digits.begin(), digits.end());
//         digits[0] += 1;
//         int carry = digits[0] / 10;
//         digits[0] %= 10;
        
//         for(int i=1 ; i<n && carry>0 ; i++) {
            
//             digits[i] += carry;
            
//             if(digits[i] > 9) {
//                 carry = digits[i] / 10;
//                 digits[i] %= 10;
//             }
//             else carry = 0;
            
//         }
        
//         if(carry) digits.push_back(carry);
//         reverse(digits.begin(), digits.end());
        
//         return digits;
    }
};