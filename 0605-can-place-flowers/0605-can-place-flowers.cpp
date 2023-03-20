class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int possibleSlots = 0;
        int m = flowerbed.size();
        
        for(int i=0 ; i<m ; i++) {
            if(flowerbed[i] == 1) i++;
            else {
                if((i+1 < m && flowerbed[i+1] == 0) || i == m-1) {
                    possibleSlots++;
                    i++;
                }
            }
        }
        
        return possibleSlots >= n;
    }
};