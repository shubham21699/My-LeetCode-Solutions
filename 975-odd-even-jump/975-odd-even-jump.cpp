class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        
//         We need to jump higher and lower alternately to the end.

//         Take [5,1,3,4,2] as example.

//         If we start at 2,
//         we can jump either higher first or lower first to the end,
//         because we are already at the end.
//         higher(2) = true
//         lower(2) = true

//         If we start at 4,
//         we can't jump higher, higher(4) = false
//         we can jump lower to 2, lower(4) = higher(2) = true

//         If we start at 3,
//         we can jump higher to 4, higher(3) = lower(4) = true
//         we can jump lower to 2, lower(3) = higher(2) = true

//         If we start at 1,
//         we can jump higher to 2, higher(1) = lower(2) = true
//         we can't jump lower, lower(1) = false

//         If we start at 5,
//         we can't jump higher, higher(5) = false
//         we can jump lower to 4, lower(5) = higher(4) = false
        
        int n = arr.size();
        map<int, int> mp;
        mp[arr[n-1]] = n-1;
        
        vector<int> higher(n), lower(n);
        higher[n-1] = lower[n-1] = 1;
        
        int res = 1;
        
        for(int i=n-2 ; i>=0 ; i--) {
            
            // lower_bound = ceiling element iterator
            // upper_bound = floor element iterator
            auto high = mp.lower_bound(arr[i]);
            auto low = mp.upper_bound(arr[i]);
            
            if(high != mp.end()) higher[i] = lower[high->second];
            if(low != mp.begin()) lower[i] = higher[(--low)->second];
            
            if(higher[i]) res++;
            mp[arr[i]] = i;
        }
        
        return res;
    }
};