class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int n = num.size();
        reverse(num.begin(), num.end());
        int i = 0;
        int carry = 0;
        
        while(k || carry) {
            
            int val = (i<n ? num[i] : 0) + k%10 + carry;
            
            if(val > 9) {
                carry = floor(val / 10.0);
                val %= 10;
            }
            else carry = 0;
            
            if(i < n) num[i] = val;
            else num.push_back(val);
            
            i++;
            k /= 10;
        }
        
        reverse(num.begin(), num.end());
        return num;
    }
};