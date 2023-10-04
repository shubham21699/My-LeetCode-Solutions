class Solution {
public:
    vector<int> leftSmaller(vector<int>& maxHeights, int n) {
        
        stack<pair<int, int>> st;
        vector<int> prevSmaller(n, -1);
        
        // Get index to nearest smaller value on left [0, i-1]
        for(int i=0 ; i<n ; i++) {
            while(!st.empty() && st.top().first >= maxHeights[i]) {
                st.pop();
            }
            
            if(!st.empty()) prevSmaller[i] = st.top().second;
            st.push({ maxHeights[i], i });
        }
        
        return prevSmaller;
    } 
    
    vector<int> rightSmaller(vector<int>& maxHeights, int n) {
        
        stack<pair<int, int>> st;
        vector<int> nextSmaller(n, n);
        
        // Get index to nearest smaller value on right [i+1, n-1]
        for(int i=n-1 ; i>=0 ; i--) {
            while(!st.empty() && st.top().first >= maxHeights[i]) {
                st.pop();
            }
            
            if(!st.empty()) nextSmaller[i] = st.top().second;
            st.push({ maxHeights[i], i });
        }
        
        return nextSmaller;
    }
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        int n = maxHeights.size();
        if(n == 1) return maxHeights[0];
        if(n == 2) return (long long) (maxHeights[0] + maxHeights[1]);
        
        vector<int> left = leftSmaller(maxHeights, n);
        vector<int> right = rightSmaller(maxHeights, n);
        
        vector<long long> leftSum(n, 0);
        vector<long long> rightSum(n, 0);
        
        for(int i=0 ; i<n ; i++) {
            int prevSmaller = left[i];
            
            // indexes from [prevSmaller+1] to [i] will have height = maxHeights[i]
            leftSum[i] = (long long) (i - prevSmaller) * maxHeights[i];
            if(prevSmaller != -1) leftSum[i] += leftSum[prevSmaller];
        }
        
        for(int i=n-1 ; i>=0 ; i--) {
            int nextSmaller = right[i];
            
            // indexes from [i] to [nextSmaller-1] will have height = maxHeights[i]
            rightSum[i] = (long long) (nextSmaller - i) * maxHeights[i];
            if(nextSmaller != n) rightSum[i] += rightSum[nextSmaller];
        }
        
        long long result = 0;
        
        for(int i=0 ; i<n ; i++) {
            result = max(result, leftSum[i] + rightSum[i] - maxHeights[i]);
        }
        
        return result;
    }
};