class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int n = arr.size();
        if(n <= 2 || arr[0] > arr[1] || arr[n-1] > arr[n-2]) return false;
        
        int peak_count = 0;
        for(int i=0 ; i<n-1 ; i++) {
            
            if(arr[i] == arr[i+1]) return false;
            if(i>0 && arr[i] > arr[i-1] && arr[i] > arr[i+1]) peak_count++;
            
        }
        
        if(peak_count == 1) return true;
        return false;
    }
};