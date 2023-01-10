class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());
        
        long long score = 0;
        
        while(!pq.empty() && k>0) {
            int x = pq.top();
            pq.pop();
            score += x;
            pq.push(ceil(x / 3.0));
            k--;
        }
        
        return score;
    }
};