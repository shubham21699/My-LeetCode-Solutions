class Solution {
    int getEleGreaterThanOrEqualToMid(vector<vector<int> >& matrix, int n, int num) {
        
        int count = 0;
        int row = 0;
        int col = n-1; // Start with rightmost column
        
        for(row=0 ; row<n ; row++) {
            
            while(col>=0 && matrix[row][col] > num) {
                col--; // Decrease column untill matrix[row][col] <= num
            }
            
            count += (col+1);
        }
        
        return count;
        
        
////////////////////// OR: /////////////////////////////////////////
//         int result = 0;
        
//         for(int i=0 ; i<n ; i++) {
            
//             // If num is less than first element, then no more element are 
//             // futher less than or equal or equal to num
//             if(num < matrix[i][0]) return result;
            
//             // If num is greater than last element, then it is greater than 
//             // all the elements in that row
//             if(num >= matrix[i][n-1]) {
//                 result += n;
//                 continue;
//             }
            
//             // This contain the column index of last element in matrix less than of equal to num
//             int greaterThan = 0;
            
//             for(int jump=n/2 ; jump>=1 ; jump/=2) {
                
//                 while(greaterThan+jump < n && matrix[i][greaterThan+jump] <= num) {
//                     greaterThan += jump;
//                 }
                
//             }
            
//             result += greaterThan+1;
//         }
        
//         return result;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        if(k == 1) return matrix[0][0];
        if(k == n*n) return matrix[n-1][n-1];
        
        
        // Using Binary Search:
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while(left <= right) {
            
            int mid = left + (right - left)/2;
            
            int greaterThanOrEqualToMid = getEleGreaterThanOrEqualToMid(matrix, n, mid);
            
            if(greaterThanOrEqualToMid >= k) right = mid-1;
            else left = mid+1;
            
        }
        
        return left;

        
//         OR: Using Heap Sort
//         priority_queue<int, vector<int>, greater<int> > pq;
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<n ; j++) {
//                 pq.push(matrix[i][j]);
//             }
//         }
        
//         while(k > 1) {
//             pq.pop();
//             k--;
//         }
        
//         return pq.top();
        
    }
};