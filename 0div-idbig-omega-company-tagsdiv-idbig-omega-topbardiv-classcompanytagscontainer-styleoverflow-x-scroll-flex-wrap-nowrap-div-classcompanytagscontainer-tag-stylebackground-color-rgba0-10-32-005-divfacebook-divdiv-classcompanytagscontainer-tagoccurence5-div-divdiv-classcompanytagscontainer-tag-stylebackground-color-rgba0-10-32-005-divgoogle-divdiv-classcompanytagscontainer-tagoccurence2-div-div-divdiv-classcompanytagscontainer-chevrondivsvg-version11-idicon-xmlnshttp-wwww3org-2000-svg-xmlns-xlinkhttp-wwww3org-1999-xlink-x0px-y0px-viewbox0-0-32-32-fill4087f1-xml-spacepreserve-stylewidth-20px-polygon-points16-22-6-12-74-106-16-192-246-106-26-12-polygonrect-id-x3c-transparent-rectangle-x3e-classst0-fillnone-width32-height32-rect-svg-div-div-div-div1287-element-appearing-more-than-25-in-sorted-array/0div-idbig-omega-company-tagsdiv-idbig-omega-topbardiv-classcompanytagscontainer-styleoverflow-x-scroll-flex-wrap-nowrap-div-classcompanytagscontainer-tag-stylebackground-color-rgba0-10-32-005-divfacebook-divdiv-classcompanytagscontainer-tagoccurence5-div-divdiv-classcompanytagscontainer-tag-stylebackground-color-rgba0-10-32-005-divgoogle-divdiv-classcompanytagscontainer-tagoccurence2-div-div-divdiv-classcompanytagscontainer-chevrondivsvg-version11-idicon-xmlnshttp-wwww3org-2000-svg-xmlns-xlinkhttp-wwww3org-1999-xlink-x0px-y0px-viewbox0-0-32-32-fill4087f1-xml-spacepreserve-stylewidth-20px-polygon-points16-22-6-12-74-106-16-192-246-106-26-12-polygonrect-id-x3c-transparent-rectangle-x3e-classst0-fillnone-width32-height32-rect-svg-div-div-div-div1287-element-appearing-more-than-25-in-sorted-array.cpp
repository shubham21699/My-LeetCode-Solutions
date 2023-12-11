class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n = arr.size();
        int morethan25 = n/4;
        
        for(int i=0 ; i<n-morethan25 ; i++) {
            if(arr[i] == arr[i+morethan25]) return arr[i];
        }
        
//         // OR:-
//         unordered_map<int, int> freq;
        
//         for(int i=0 ; i<n ; i++) {
//             freq[arr[i]]++;
//             if(freq[arr[i]] > morethan25) return arr[i];
//         }
        
        return -1;
    }
};