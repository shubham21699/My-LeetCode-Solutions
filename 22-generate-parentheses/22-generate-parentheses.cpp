class Solution {
    void generate(vector<string>& result, string s, int opening_count, int closing_count, int n) {
        
        if(opening_count == closing_count && s.length() == 2*n) {
            result.push_back(s);
            return;
        }
        
        if(opening_count < n) generate(result, s+'(', opening_count+1, closing_count, n);
        if(opening_count > closing_count) generate(result, s+')', opening_count, closing_count+1, n);
        
    }
    
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        if(n == 1) {
            result.push_back("()");
            return result;
        }
        
        string s = "(";
        generate(result, s, 1, 0, n);
        return result;
    }
};