class Solution {
//     int score(vector<int>& cardPoints, int k, int index, int n) {
        
//         if(k == 0 || index >= n) return 0;
        
//         return max(cardPoints[index] + score(cardPoints, k-1, index+1, n), cardPoints[n-1] + score(cardPoints, k-1, index, n-1));
//     }
    
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        if(n == k) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(k == 1) return max(cardPoints[0], cardPoints[n-1]);
        if(n-1 == k) 
            return accumulate(cardPoints.begin(), cardPoints.end(), 0) - *min_element(cardPoints.begin(), cardPoints.end());
        
        int total = 0;
        for(int i=0 ; i<k ; i++) total += cardPoints[i];
        
        int bestScore = total;
        
        for(int i=k-1, j=n-1 ; ~i ; i--, j--) {
            total += cardPoints[j] - cardPoints[i];
            bestScore = max(bestScore, total);
        }
        
        return bestScore;
        
        // RECURSIVE APPROACH : GIVE TLE
        // int sum = 0;
        // return max(cardPoints[0] + score(cardPoints, k-1, 1, n), cardPoints[n-1] + score(cardPoints, k-1, 0, n-1));
    }
};