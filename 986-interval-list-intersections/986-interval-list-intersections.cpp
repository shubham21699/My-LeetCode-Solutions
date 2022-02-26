class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int n = firstList.size();
        int m = secondList.size();
        if(n == 0 || m == 0) return {};
        
        int i = 0;
        int j = 0;
        vector<vector<int>> result;
        
        while(i < n && j < m) {
            
            if(firstList[i][0] > secondList[j][1]) {
                j++;
            }
            else if(firstList[i][1] < secondList[j][0]) {
                i++;
            }
            else {
                
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);
                result.push_back({ start, end });
                
                if(firstList[i][1] < secondList[j][1]) i++;
                else j++;
                
            }
            
        }
        
        return result;
    }
};