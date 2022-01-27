class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0, mask = 0;
        
        for(int i=31 ; i>=0 ; i--) {
            
            mask = mask | (1 << i);
            int greedyAns = (ans | (1 << i));
            
            // Check if possible
            unordered_set<int> s;
            for(auto num : nums) {
                // We basically insert with first i bits conserved and the rest of the bits are 0 after 1
                s.insert(num & mask);
            }
            
            for(auto prefix : s) {
                
                if(s.find(greedyAns xor prefix) != s.end()) {
                    ans = greedyAns;
                    break;
                }
                
            }
            
        }
        
        return ans;
        
        
//         OR: Will give TLE
//         priority_queue<int> pq;
        
//         for(int i=0 ; i<n ; i++) {
//             for(int j=i ; j<n ; j++) {
//                 int x = nums[i] xor nums[j];
//                 pq.push(x);
//             }
//         }
        
//         return pq.top();
    }
};