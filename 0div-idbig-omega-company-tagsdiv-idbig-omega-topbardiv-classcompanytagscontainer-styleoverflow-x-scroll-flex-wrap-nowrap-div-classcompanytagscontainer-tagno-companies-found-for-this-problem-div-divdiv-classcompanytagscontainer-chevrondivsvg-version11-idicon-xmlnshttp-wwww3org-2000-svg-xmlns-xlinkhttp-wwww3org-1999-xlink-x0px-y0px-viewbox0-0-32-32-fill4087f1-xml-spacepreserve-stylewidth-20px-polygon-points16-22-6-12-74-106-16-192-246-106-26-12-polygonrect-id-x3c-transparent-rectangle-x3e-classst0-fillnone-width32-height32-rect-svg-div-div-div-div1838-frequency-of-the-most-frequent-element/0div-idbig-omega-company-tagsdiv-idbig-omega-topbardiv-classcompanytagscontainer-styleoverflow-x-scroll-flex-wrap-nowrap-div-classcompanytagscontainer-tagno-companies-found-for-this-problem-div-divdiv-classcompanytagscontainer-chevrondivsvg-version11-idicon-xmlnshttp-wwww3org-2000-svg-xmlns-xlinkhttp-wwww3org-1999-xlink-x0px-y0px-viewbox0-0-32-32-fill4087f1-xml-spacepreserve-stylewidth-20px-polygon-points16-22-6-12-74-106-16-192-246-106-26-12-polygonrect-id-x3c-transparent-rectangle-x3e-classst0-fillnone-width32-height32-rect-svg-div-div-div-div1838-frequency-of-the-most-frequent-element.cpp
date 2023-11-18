class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxFreq = 0; // Initialize the maximum frequency
        long long currSum = 0; // Initialize the current sum of the subarray elements
        sort(nums.begin(), nums.end());
        
        for(int left=0, right=0 ; right<n ; right++) {
            currSum += nums[right]; // Include the current element in the subarray sum
            
             // Check if the current subarray violates the condition (sum + k < nums[right] * length)
            while(currSum+k < 1LL * nums[right] * (right - left + 1)) {
                currSum -= nums[left];  // Adjust the subarray sum by removing the leftmost elemen
                left++; // Move the left pointer to the right
            }
            
            // Update the maximum frequency based on the current subarray length
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};