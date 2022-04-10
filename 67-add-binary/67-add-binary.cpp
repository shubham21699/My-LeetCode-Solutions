class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.length()-1;
        int m = b.length()-1;
        string result;
        int carry = 0;
        
        while(n>=0 || m>=0 || carry) {
            
            int val = (n>=0 ? a[n]-'0' : 0) + (m>=0 ? b[m]-'0' : 0) +  carry;
            if(val == 3) {
                val = 1;
                carry = 1;
            }
            else if(val == 2) {
                val = 0;
                carry = 1;
            }
            else carry = 0;
            
            result.insert(0, to_string(val));
            n--;
            m--;
            
        }
        
        return result;
    }
};