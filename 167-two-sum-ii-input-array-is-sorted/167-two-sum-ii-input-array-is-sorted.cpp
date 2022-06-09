class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        if(n == 2) {
            return { 1, 2 };
        }
        
        int i = 0;
        int j = n-1;
        
        while(i < j) {
            int x = numbers[i] + numbers[j];
            
            if(x == target) break;
            else if(x > target) j--;
            else i++;
            
        }
        
        return { i+1, j+1 };
        
        
//         // OR:-
//         vector<int> result(2);
//         unordered_map<int, int> mp;
        
//         for(int i=0 ; i<n ; i++) {
//             if(mp.find(target-numbers[i]) != mp.end() && mp[target-numbers[i]] < i) {
//                 result[0] = mp[target-numbers[i]]+1;
//                 result[1] = i+1;
//                 break;
//             }
            
//             mp[numbers[i]] = i;
//         }
        
//         return result;
    }
};