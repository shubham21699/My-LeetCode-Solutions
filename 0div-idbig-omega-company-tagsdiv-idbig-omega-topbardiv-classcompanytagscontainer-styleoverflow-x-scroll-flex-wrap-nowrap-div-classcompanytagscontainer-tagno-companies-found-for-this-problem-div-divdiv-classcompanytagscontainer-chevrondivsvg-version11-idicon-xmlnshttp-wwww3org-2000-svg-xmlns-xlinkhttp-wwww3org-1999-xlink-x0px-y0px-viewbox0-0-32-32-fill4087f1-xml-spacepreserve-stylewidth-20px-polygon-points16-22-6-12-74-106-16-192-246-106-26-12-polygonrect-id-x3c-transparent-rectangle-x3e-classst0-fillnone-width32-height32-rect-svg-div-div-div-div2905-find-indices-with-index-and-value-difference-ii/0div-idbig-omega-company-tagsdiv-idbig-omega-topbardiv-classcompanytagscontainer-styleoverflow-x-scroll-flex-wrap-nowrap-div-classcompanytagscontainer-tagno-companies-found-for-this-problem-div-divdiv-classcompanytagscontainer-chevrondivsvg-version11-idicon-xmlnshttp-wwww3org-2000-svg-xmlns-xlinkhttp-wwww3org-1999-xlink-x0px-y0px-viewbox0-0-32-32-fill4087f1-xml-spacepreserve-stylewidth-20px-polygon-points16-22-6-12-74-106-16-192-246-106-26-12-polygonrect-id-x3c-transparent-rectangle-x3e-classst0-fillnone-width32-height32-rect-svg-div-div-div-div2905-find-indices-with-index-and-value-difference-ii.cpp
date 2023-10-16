class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        int n = nums.size();
        
        int maxi = 0, mini = 0;
        
        for(int i=indexDifference ; i<n ; i++) {
            if(nums[i-indexDifference] > nums[maxi]) maxi = i - indexDifference;
            if(nums[i-indexDifference] < nums[mini]) mini = i - indexDifference;
            
            if(nums[maxi] - nums[i] >= valueDifference) return { maxi, i };
            if(nums[i] - nums[mini] >= valueDifference) return { i, mini };
        }
        
        return { -1, -1 };
        
        
//         // OR:-
//         priority_queue<pair<int, int>> maxi;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mini;
        
//         for(int i=0 ; i<n ; i++) {
//             maxi.push({ nums[i], i });
//             mini.push({ nums[i], i });
//         }
        
//         for(int i=0 ; i<n ; i++) {
//             while(!maxi.empty() && maxi.top().second < i + indexDifference) maxi.pop();
//             while(!mini.empty() && mini.top().second < i + indexDifference) mini.pop();
            
//             if(!maxi.empty() && abs(nums[i] - maxi.top().first) >= valueDifference) 
//                 return { i, maxi.top().second };
//             if(!mini.empty() && abs(nums[i] - mini.top().first) >= valueDifference) 
//                 return { i, mini.top().second };
//         }
        
//         return { -1, -1 };
    }
};