class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 1 && m == 1) return matrix[0][0]-'0';
        
        vector<vector<int> > rect(n, vector<int>(m, 0));
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                rect[i][j] = matrix[i][j] == '0' ? 0 : 1;
            }
        }
        
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(rect[i][j]) rect[i][j] += rect[i-1][j];
            }
        }
        
        int maxArea = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            stack<int> s;
            int j = 0;
            
            while(j < m) {
                
                while(!s.empty() && rect[i][j] <= rect[i][s.top()]) {
                    
                    // If this element is lower than top of stack, then calculate area of rectangle
                    // with top of stack as the smallest bar.
                    // 'j' is the 'right index' for the top and element before top in stack is 'left index'.
                    int height = rect[i][s.top()];
                    s.pop();
                    
                    int area = height * (s.empty() ? j : (j - s.top() - 1));
                    maxArea = max(maxArea, area);
                    
                }
                
                s.push(j);
                j++;
            }
            
            // Now pop the remaining elements from stack and calculate area with every popped element
            // as the smallest element.
            while(!s.empty()) {
                    
                int height = rect[i][s.top()];
                s.pop();
                    
                int area = height * (s.empty() ? j : (j - s.top() - 1));
                maxArea = max(maxArea, area);
                    
            }
            
        }
        
        return maxArea;
    }
};