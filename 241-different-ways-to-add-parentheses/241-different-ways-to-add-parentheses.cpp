class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        int n = expression.size();
        vector<int> result;
        
        for(int i=0 ; i<n ; i++) {
            
            char op = expression[i];
            
            if(op == '+' || op == '-' || op == '*') {
                
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                
                for(int n1 : left) {
                    for(int n2 : right) {
                        if(op == '+') result.push_back(n1 + n2);
                        else if(op == '-') result.push_back(n1 - n2);
                        else if(op == '*') result.push_back(n1 * n2);
                    }
                }
                
            }
            
        }
        
        if(result.empty()) result.push_back(stoi(expression));
        return result;
    }
};