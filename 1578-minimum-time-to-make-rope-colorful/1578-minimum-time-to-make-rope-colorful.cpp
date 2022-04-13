class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.length();
        if(n == 1) return 0;
        
        int timeTaken = 0;
        int i = 0;
        
        while(i < n-1) {
            if(colors[i] == colors[i+1]) {
                
                char ch = colors[i];
                int j = i;
                int ch_times = 0;
                int max_time = 0;
                
                while(j<n && colors[j] == ch) {
                    ch_times += neededTime[j];
                    max_time = max(max_time, neededTime[j]);
                    j++;
                }
                
                timeTaken += abs(ch_times - max_time);
                i = j;
                
            }
            else i++;
            
        }
        
        return timeTaken;
    }
};