class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.length();
        string result = "";
        
        for(int i=n-1 ; i>=0 ; i--) {
            
            if((num[i]-'0') % 2 != 0) { // If current digit is odd
                // Then we get the largest-valued odd number from first digit till here as last digit is odd.
                result = num.substr(0, i+1);
                break;
            }
        }
        
        return result;
    }
};