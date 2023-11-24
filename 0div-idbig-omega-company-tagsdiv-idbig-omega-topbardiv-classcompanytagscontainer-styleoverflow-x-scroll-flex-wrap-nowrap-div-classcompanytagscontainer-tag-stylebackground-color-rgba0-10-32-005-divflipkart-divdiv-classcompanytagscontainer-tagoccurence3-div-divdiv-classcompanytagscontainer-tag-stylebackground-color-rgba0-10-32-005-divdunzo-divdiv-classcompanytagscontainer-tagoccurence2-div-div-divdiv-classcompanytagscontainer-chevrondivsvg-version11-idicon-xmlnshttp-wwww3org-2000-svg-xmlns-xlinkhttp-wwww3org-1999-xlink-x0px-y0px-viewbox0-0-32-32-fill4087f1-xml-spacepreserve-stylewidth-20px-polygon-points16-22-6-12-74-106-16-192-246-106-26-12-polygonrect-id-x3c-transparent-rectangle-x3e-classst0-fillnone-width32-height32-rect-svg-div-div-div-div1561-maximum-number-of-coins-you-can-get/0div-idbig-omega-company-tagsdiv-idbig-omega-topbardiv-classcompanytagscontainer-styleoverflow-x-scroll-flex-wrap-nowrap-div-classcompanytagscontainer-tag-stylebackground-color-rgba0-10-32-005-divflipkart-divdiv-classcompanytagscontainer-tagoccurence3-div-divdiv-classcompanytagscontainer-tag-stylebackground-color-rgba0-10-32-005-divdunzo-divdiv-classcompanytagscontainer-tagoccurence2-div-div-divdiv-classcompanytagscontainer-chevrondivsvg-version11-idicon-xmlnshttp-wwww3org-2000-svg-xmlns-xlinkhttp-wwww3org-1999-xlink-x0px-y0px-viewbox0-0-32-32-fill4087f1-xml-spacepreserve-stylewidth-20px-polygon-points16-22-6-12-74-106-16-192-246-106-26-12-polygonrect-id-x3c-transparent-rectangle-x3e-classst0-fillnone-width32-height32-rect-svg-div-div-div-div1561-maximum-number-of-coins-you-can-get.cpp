class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int result = 0;
        int i = 0, j = n-1;
        
        while(i < j) {
            
            // Pick 3 coins - 2 highest and 1 smallest
            // Alice will get the highest coin i.e. jth coin, 
            // I will get 2nd highest coin i.e. (j-1)th coin, 
            // and Bob will get the smallest one i.e. ith coin
            result += piles[j-1];
            j -= 2;
            i++;
            
        }
        
        return result;
    }
};