class Solution {
public:
    int twoEggDrop(int n) {
        
        int count = 0;
        int sum = 0;
        
        while(sum < n) {
            sum += count;
            count++;
        }
        
        return count-1;
    }
};