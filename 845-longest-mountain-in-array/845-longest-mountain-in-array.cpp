class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size();
        int maxLen = 0;
        
        for(int k=1 ; k<n-1 ; k++) {
            
            if(arr[k] > arr[k-1] && arr[k] > arr[k+1]) {
                
                int i = k;
                int j = k;

                while(i > 0 && arr[i] > arr[i-1]) i--;
                while(j < n-1 && arr[j] > arr[j+1]) j++;

                maxLen = max(maxLen, j-i+1);
                k = j;
            }
            
        }
        
        return maxLen;
    }
};