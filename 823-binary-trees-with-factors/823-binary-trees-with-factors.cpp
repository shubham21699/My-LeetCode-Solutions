class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        long long count = 0;
        unordered_map<int, long long> freq;
        
        for(int i=0 ; i<n ; i++) {
            
            long long ways = 1;
            double sqrtOfNum = sqrt(arr[i]);
            
            for(int j=0, k=arr[0] ; k<=sqrtOfNum ; k=arr[++j]) {
                
                if(arr[i] % k != 0) continue;
                
                int l = arr[i] / k;
                
                if(freq.find(l) != freq.end()) {
                    ways = (ways + freq[k] * freq[l] * (k == l ? 1 : 2)) % mod;
                }
                
            }
            
            freq[arr[i]] = ways;
            count  = (count + ways) % mod;
        }
        
        return count;
    }
};