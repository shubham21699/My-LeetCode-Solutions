class Solution {
public:
    string largestGoodInteger(string num) {
        
        int n = num.size();
        string result = "";
        int maxi = -1;
        
        for(int i=2 ; i<n ; i++) {
            if(num[i] == num[i-1] && num[i] == num[i-2] && num[i]-'0' > maxi) {
                result = num.substr(i-2, 3);
                maxi = num[i]-'0';
            }
        }
        
        return result;
    }
};