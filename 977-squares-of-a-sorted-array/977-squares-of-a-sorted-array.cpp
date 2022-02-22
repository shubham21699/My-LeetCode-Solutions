class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return { nums[0]*nums[0] };
        
        vector<int> result(n);
        int k = 0;
        int l = n-1;
        
        for(int i=n-1 ; i>=0 ; i--) {
            
            if(abs(nums[k]) > abs(nums[l])) result[i] = nums[k] * nums[k++];
            else result[i] = nums[l] * nums[l--];
            
        }
        
        return result;
        
        
//         OR: Takes More Memory
//         priority_queue<int, vector<int>, greater<int> > pq;
        
//         for(int i=0 ; i<n ; i++) {
//             pq.push({ nums[i] * nums[i] });
//         }
        
//         vector<int> result;
        
//         while(!pq.empty()) {
//             result.push_back(pq.top());
//             pq.pop();
//         }
        
//         return result;
    }
};