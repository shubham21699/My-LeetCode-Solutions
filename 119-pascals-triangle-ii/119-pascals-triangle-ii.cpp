class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1, 1};
        if(rowIndex == 2) return {1, 2, 1};
        
        vector<vector<int>> pascal;
        
        for(int i=0 ; i<=rowIndex ; i++) {
            pascal.push_back(vector<int>(i+1, 1));
            
            for(int j=1 ; j<i ; j++) {
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
            
        }
        
        return pascal.back();
        
//         OR:
//         vector<int> ans(rowIndex+1, 1);
        
//         for(int i=0 ; i<rowIndex ; i++) {
//             for(int j=i ; j>0 ; j--) {
//                 ans[j] = ans[j] + ans[j-1];
//             }
//         }
        
//         return ans;
    }
};