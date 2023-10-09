class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        
        int n = processorTime.size();
        int m = tasks.size();
        
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());
        
        int i = 0, j = 0;
        int result = 0;
        
        while(i < n && j < m) {
            
            result = max(result, processorTime[i] + tasks[j]);
            
            if((j+1) % 4 == 0) i++;
            j++;
        }
        
        return result;
    }
};