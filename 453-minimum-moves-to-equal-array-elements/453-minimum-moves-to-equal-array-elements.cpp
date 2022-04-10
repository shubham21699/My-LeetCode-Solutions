class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        // Find minimum elementt in the array
        int mini = *min_element(nums.begin(), nums.end());
        
        // We are doing just opposite of the problem. Instead of incrementing n-1 elements, 
        // we are decrementing 1 element at a time.
        // So, subtract every element by min element which gives us the value if how much 
        // decrement is needs to become equal to min element in array,
        for(int i=0 ; i<nums.size() ; i++) {
            nums[i] -= mini;
        }
        
        // Adding all the decremented values will give us total number of steps required.
        return accumulate(nums.begin(), nums.end(), 0);
    }
};