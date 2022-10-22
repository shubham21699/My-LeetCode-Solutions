class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
        int resultID = logs[0][0];
        int maxDiff = logs[0][1];
        int m = logs.size();
        
        for(int i=1 ; i<m ; i++) {
            if(logs[i][1] - logs[i-1][1] > maxDiff) {
                maxDiff = logs[i][1] - logs[i-1][1];
                resultID = logs[i][0];
            }
            else if(logs[i][1] - logs[i-1][1] == maxDiff) {
                maxDiff = logs[i][1] - logs[i-1][1];
                resultID = min(resultID, logs[i][0]);
            }
        }
        
        return resultID;
    }
};