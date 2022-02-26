class Solution {
    struct mycomp {
        bool operator()(vector<int>& v1, vector<int>& v2) {
            return v1[0] + v1[1] < v2[0] + v2[1];
        }
    };
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        if(k == 1 || (n == 1 && m == 1)) return {{ nums1[0], nums2[0] }};
        
        priority_queue<vector<int>, vector<vector<int>>, mycomp > pq;
        
        for(int i=0 ; i<min(n, k) ; i++) {
            for(int j=0 ; j<min(m, k) ; j++) {
                
                if(pq.size() < k) {
                    pq.push({ nums1[i], nums2[j] });
                }
                else if(nums1[i] + nums2[j] < pq.top()[0] + pq.top()[1]) {
                    pq.pop();
                    pq.push({ nums1[i], nums2[j] });
                }
                else break;
                
            }
        }
        
        vector<vector<int>> result;
        
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
        
        
//         OR: Will give TLE
//         priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>> > pq;
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<m ; j++) {
//                 int sum = nums1[i] + nums2[j];
//                 vector<int> v(2);
//                 v[0] = nums1[i];
//                 v[1] = nums2[j];
//                 pq.push({ sum, v });
//             }
//         }
        
//         vector<vector<int>> result;
        
//         while(!pq.empty() && k--) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
        
//         return result;
    }
};