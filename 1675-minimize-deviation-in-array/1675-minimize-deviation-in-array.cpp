class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int n = nums.size();
        priority_queue<int> p; // Max-Heap
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i]%2 != 0) nums[i] *= 2;
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
            p.push(nums[i]);
        }
        
        int minDeviation = maxi - mini;
        if(minDeviation == 1) return 1;
        
        while(p.top()%2 == 0) {
            
            maxi = p.top();
            p.pop();
            
            minDeviation = min(minDeviation, maxi - mini);
            maxi /= 2;
            
            mini = min(mini, maxi);
            p.push(maxi);
            
        }
        
        minDeviation = min(minDeviation, p.top() - mini);
        return minDeviation;
    }
};