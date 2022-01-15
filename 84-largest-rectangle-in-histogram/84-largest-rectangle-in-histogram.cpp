class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        heights.push_back(0);
        int n = heights.size();
        
        if(n == 1) return heights[0];
        if(n == 2) {
            return max({ heights[0], heights[1], min(heights[0], heights[1])*2 });
        }
        
        stack<int> s;
        int maxArea = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!s.empty() && heights[i] <= heights[s.top()]) {
                
                int height = heights[s.top()];
                s.pop();
                // Here, i is right index(current index) and s.top() is left index(previous index)
                int area = height * ( s.empty() ? i : (i - s.top() - 1));
                maxArea = max(maxArea, area);
                
            }
            
            s.push(i);
        }
        
        return maxArea;
    }
};