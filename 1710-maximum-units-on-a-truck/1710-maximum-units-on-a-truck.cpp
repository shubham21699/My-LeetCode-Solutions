class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
        });
        
        int units = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(truckSize <= boxTypes[i][0]) {
                units += (truckSize * boxTypes[i][1]);
                break;
            }
            else {
                units += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
        }
        
        return units;
    }
};