class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string result = "";
        int n = num1.length()-1;
        int m = num2.length()-1;
        int carry = 0;
        
        while(n>=0 || m>=0 || carry) {
            
            int val = (n>=0 ? num1[n]-'0' : 0 ) + (m>=0 ? num2[m]-'0' : 0) + carry;
            if(val > 9) {
                carry = val/10;
                val %= 10;
            }
            else carry = 0;
            
            result.insert(0, to_string(val));
            n--;
            m--;
        }
        
        return result;
    }
};