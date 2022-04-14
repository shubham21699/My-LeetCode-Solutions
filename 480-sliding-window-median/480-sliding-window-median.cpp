class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k == 1) return vector<double>(nums.begin(), nums.end());
        
        multiset<int> window(nums.begin(), nums.begin()+k);
        auto mid = next(window.begin(), k/2);
        
        vector<double> median;
        
        for(int i=k ; ; i++) {
            
            // Push the current median.
            median.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);
            
            // If all done, return.
            if(i == n) return median;
            
            // Insert nums[i]
            window.insert(nums[i]);
            if(nums[i] < *mid) {
                mid--;
            }
            
            // Erase nums[i-k]
            if(nums[i-k] <= *mid) {
                mid++;
            }
            
            window.erase(window.lower_bound(nums[i-k]));
            
        }
        
        return median;
        
        
//         // OR: Will Give TLE
//         vector<double> result;
//         int j = 0;
//         vector<int> v;
        
//         for(int i=0 ; i<n ; i++) {
            
//             v.push_back(nums[i]);
            
//             if(v.size() == k) {
//                 vector<int> arr = v;
//                 sort(arr.begin(), arr.end());
//                 double mid = 0;
//                 if(k % 2 == 0){
//                     mid = (arr[k/2])/2.0 + (arr[(k/2)-1])/2.0;
//                 }
//                 else mid = arr[k/2] / 1.0;
//                 result.push_back(mid);
                
//                 v.erase(v.begin());
//             }
            
//         }
        
//         return result;
    }
};