class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        
        int n = brackets.size();
        if(income == 0) return 0.0;
        if(brackets[0][0] > income) {
            return double(income * double(brackets[0][1]/100.0));
        }
        
        double earn = 0.0;
        earn = brackets[0][0] * (brackets[0][1]/100.0);
        
        for(int i=1 ; i<n ; i++) {
            if(brackets[i][0] > income) {
                earn += double((income - brackets[i-1][0]) * double(brackets[i][1]/100.0));
                break;
            }
            else
                earn += double((brackets[i][0]-brackets[i-1][0]) * double(brackets[i][1]/100.0));
        }
        
        return earn;
    }
};