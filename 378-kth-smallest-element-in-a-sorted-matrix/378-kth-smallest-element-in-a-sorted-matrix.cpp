class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        if(k == 1) return matrix[0][0];
        if(k == n*n) return matrix[n-1][n-1];
        
        auto cmp = [&](pair<int,int> a,pair<int,int> b){
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > pq(cmp);
        
        for(int i=0 ; i<n ; i++) pq.push({ i, 0 });
        
        while(k > 1) {
            
            pair<int, int> p = pq.top();
            pq.pop();
            
            if(p.second+1 < n) {
                pq.push({ p.first, p.second+1 });
            }
            
            k--;
        }
        
        return matrix[pq.top().first] [pq.top().second];
        
        
//         OR:
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