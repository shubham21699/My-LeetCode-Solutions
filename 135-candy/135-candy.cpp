class Solution {
public:
    int candy(vector<int>& ratings) {
        
         int n = ratings.size();
        if(n == 1) return 1;
        
        vector<int> v(n, 1);
        
        for(int i=1 ; i<n ; i++) {
            if(ratings[i] > ratings[i-1]) {
                v[i] = v[i-1] + 1;
            }
        }
        
        for(int i=n-2 ; i>=0 ; i--) {
            if(ratings[i] > ratings[i+1]) {
                v[i] = max(v[i], v[i+1] + 1);
            }
        }
        
        int result = 0;
        
        for(int i=0 ; i<n ; i++) result += v[i];
        
        return result;
        
        
/////////////////////// OR ///////////////////////////////         
//         vector<int> left(n, 1);
//         vector<int> right(n, 1);
        
//         if(ratings[0] > ratings[1]) left[0]++;
//         for(int i=1 ; i<n ; i++) {
//             if(ratings[i] > ratings[i-1]) {
//                 left[i] = left[i-1] + 1;
//             }
//         }
        
//         if(ratings[n-1] > ratings[n-2]) right[n-1]++;
//         for(int i=n-2 ; i>=0 ; i--) {
//             if(ratings[i] > ratings[i+1]) {
//                 right[i] = right[i+1] + 1;
//             }
//         }
        
//         int result = 0;
        
//         for(int i=0 ; i<n ; i++) {
//             result += max(left[i], right[i]);
//         }
        
//         return result;
        
    }
};