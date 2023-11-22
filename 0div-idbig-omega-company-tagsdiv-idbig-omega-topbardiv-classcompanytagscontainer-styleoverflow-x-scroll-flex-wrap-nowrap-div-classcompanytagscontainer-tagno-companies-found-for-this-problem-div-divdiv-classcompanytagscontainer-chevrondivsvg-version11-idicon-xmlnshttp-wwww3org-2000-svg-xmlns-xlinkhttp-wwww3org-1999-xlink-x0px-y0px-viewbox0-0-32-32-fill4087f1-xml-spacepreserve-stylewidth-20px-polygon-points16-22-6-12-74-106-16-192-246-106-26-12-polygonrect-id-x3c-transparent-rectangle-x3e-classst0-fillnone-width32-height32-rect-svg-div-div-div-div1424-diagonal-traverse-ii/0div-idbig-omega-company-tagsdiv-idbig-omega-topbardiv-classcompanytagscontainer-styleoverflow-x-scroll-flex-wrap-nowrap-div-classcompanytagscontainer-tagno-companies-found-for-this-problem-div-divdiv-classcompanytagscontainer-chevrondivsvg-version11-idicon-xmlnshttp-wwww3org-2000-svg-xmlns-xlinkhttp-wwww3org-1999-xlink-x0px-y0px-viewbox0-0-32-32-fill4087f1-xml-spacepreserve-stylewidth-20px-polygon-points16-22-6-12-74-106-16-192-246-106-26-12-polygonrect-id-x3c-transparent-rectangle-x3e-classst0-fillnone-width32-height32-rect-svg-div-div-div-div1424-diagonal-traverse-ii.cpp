class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        int n = nums.size();
        vector<vector<int>> arr;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<nums[i].size() ; j++) {
                arr.push_back({ i+j, i, nums[i][j] }); // { sum of row & col, rowNo, val }
            }
        }
        
        // Sort in increasing order of sum of row & col.
        // If sum is same then sort in decreasing order of row number as diagonal starts from below.
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        vector<int> result;
        int k = arr.size();
        
        for(int i=0 ; i<k ; i++) {
            result.push_back(arr[i][2]);
        }
        
        return result;
    }
};