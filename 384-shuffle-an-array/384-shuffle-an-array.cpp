class Solution {
    vector<int> original;
    vector<int> shuffled;
    
public:
    Solution(vector<int>& nums) {
        original = nums;
        shuffled = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
               
        int n = shuffled.size();
        int x = rand() % n;
        int y = rand() % n;
        swap(shuffled[x], shuffled[y]);
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */