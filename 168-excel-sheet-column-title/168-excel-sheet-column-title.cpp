class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string result = "";
        if(columnNumber <= 26) {
            result += 'A'+columnNumber-1;
            return result;
        }
        
        while(columnNumber) {
            
            columnNumber--;
            result += ('A' + columnNumber%26);
            columnNumber /= 26;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};