class Solution {
public:
    int captureForts(vector<int>& forts) {
        
        int n = forts.size();
        int enemyCaptured = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(forts[i] == 1) {
                int j = i-1;
                int k = i+1;
                
                int countEnemies = 0;
                bool isEnemyCaptured = false;
                
                while(j >= 0) {
                    if(forts[j] == -1) {
                        isEnemyCaptured = true;
                        break;
                    }
                    if(forts[j] == 0) countEnemies++;
                    if(forts[j] == 1) break;
                    j--;
                }
                
                if(isEnemyCaptured) enemyCaptured = max(enemyCaptured, countEnemies);
                
                countEnemies = 0;
                isEnemyCaptured = false;
                
                while(k < n) {
                    if(forts[k] == -1) {
                        isEnemyCaptured = true;
                        break;
                    }
                    if(forts[k] == 0) countEnemies++;
                    if(forts[k] == 1) break;
                    k++;
                }
                
                if(isEnemyCaptured) enemyCaptured = max(enemyCaptured, countEnemies);
            }
        }
        
        return enemyCaptured;
    }
};