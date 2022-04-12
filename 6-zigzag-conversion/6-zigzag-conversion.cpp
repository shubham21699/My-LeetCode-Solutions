class Solution {
public:
    string convert(string s, int numRows) {
        
        int n = s.length();
        if(numRows <= 1) return s;
        
        string zigzag[numRows];
        int steps = 0;
        int row = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            zigzag[row].push_back(s[i]);
            
            if(row == 0) steps = 1;
            else if(row == numRows-1) steps = -1;
            
            row += steps;
            
        }
        
        string result = "";
        for(int i=0 ; i<numRows ; i++) {
            result += zigzag[i];
        }
        
        return result;
    }
};