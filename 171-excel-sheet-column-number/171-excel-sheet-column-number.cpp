class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int n = columnTitle.length();
        if(n == 1) return columnTitle[0] - 'A' + 1;
        
        int result = 0;
        for(int i=0 ; i<n ; i++) {
            result = result*26 + (columnTitle[i] - 'A' + 1);
        }
        
        return result;
    }
};