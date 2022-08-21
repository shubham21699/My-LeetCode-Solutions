class Solution {
public:
    void find(vector<int>& nums, int i, int n, long long sum, priority_queue<long long>& pq) {
        
        pq.push(sum);
        
        if(i >= n) return;
        
        for(int j=i ; j<n ; j++) {
            sum += nums[j];
            find(nums, j+1, n, sum, pq);
            sum -= nums[j];
        }
        
    }
    
    long long kSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long totalSum = 0;
        
        // Calculate sum of all positive numbers, i.e maxSubseqSum (2^nth sum)
        for(int i=0 ; i<n ; i++) {
            if(nums[i] > 0) totalSum += nums[i];
            nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin(), nums.end());
        
        //Maintain { subSeqSum, index taken to reduce the sum }
        priority_queue<pair<long long, int>> pq;
        
        // Push { totalSum - 1st number, 1sst number position }
        pq.push({ totalSum - nums[0], 0 });
        
        long long res = totalSum;
        
        while(k > 1) {
            
            auto curr = pq.top();
            pq.pop();
            res = curr.first;
            int i = curr.second;
            
            if(i < n-1) {
                
                // Generate next possible sum:
                // Pick current index and try with next index
                pq.push({ res + nums[i] - nums[i+1], i+1 });
                
                // Not pick current index and try with next index
                pq.push({ res - nums[i+1], i+1 });
                
            }
            
            k--;
        }
        
        return res;
        
        
//         // OR: Will give TLE
//         priority_queue<long long> pq;
        
//         find(nums, 0, n, 0, pq);
        
//         while(k>1 && !pq.empty()) {
//             pq.pop();
//             k--;
//         }
        
//         return pq.top();
    }
};