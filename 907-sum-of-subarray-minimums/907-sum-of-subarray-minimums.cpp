class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1) return arr[0];
        if(n == 2) return arr[0] + arr[1] + min(arr[0], arr[1]);
        
        // PLE: Previous Less Element
        // NLE: Next Less Element
        stack<pair<int, int>> stkPLE, stkNLE;
        
        // Left is for distance to previous less element
        // Right is for distance to next less element
        vector<int> left(n), right(n);
        
        for(int i=0 ; i<n ; i++) left[i] = i+1;
        for(int j=0 ; j<n ; j++) right[j] = n-j;
        
        for(int i=0 ; i<n ; i++) {
            
            // For Previous Less Element
            while(!stkPLE.empty() && stkPLE.top().first > arr[i]) {
                stkPLE.pop();
            }
            left[i] = stkPLE.empty() ? i+1 : i-stkPLE.top().second;
            stkPLE.push({ arr[i], i });
            
            // For Next Less Element
            while(!stkNLE.empty() && stkNLE.top().first > arr[i]) {
                auto x = stkNLE.top();
                stkNLE.pop();
                right[x.second] = i-x.second;
            }
            stkNLE.push({ arr[i], i });
            
        }
        
        long long int result = 0;
        long long int mod = 1e9+7;
        
        for(int i=0 ; i<n ; i++) {
            result = (result + (long) arr[i]*left[i]*right[i]) % mod;
        }
        
        return result;
    }
};