class Solution {
public:
    void find(vector<int>& nums1, vector<int>& nums2, int index, int n, int k, int sum, int mini, long long& score) {
        
        if(k == 0) score = max(score, (long long) sum * mini);
        
        for(int i=index ; i<n ; i++) {
            sum += nums1[i];
            int x = min(mini, nums2[i]);
            find(nums1, nums2, i+1, n, k-1, sum, x, score);
            sum -= nums1[i];
        }
        
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        long long score = 0;
        vector<vector<int>> v;
        
        for(int i=0 ; i<n ; i++) {
            v.push_back({ nums1[i], nums2[i] });
        }
        
        sort(v.rbegin(), v.rend(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            sum += v[i][0];
            pq.push(v[i][0]);
            
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k) {
                score = max(score, sum * v[i][1]);
            }
            
        }
        
        return score;
        
        // // OR: Will give TLE
        // find(nums1, nums2, 0, n, k, 0, INT_MAX, score);
        // return score;
    }
};