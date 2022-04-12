class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n = num1.length();
        int m = num2.length();
        string result(n + m, '0');
        
        for(int i=m-1 ; i>=0 ; i--) {
            
            int carry = 0;
            
            for(int j=n-1 ; j>=0 ; j--) {
             
                int val = (result[i+j+1] - '0') +  (num1[j]-'0') * (num2[i] - '0') + carry;
                if(val > 9) {
                    carry = val / 10;
                    val %= 10;
                }
                else carry = 0;
                
                result[i+j+1] = val + '0';
                
            }
            
            if(carry) result[i] += carry;
            
        }
        
        int k = 0;
        while(k<result.size() && result[k] == '0') k++;
        
        return k<result.size() ? result.substr(k) : "0";
    }
};