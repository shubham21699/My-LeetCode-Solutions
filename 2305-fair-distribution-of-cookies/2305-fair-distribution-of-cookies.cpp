class Solution {
    void distribute(vector<int>& nums, int k, vector<int>& v, int& result, int index, int n) {
        
        if(index >= n) {
            result = min(result, *max_element(v.begin(), v.end()));
            return;
        }
        
        for(int i=0 ; i<k ; i++) {
            v[i] += nums[index];
            distribute(nums, k, v, result, index+1, n);
            v[i] -= nums[index];
        }
        
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size();
        if(n == 2) return max(cookies[0], cookies[1]);
        sort(cookies.begin(), cookies.end());
        int result = INT_MAX;
        
        vector<int> v(k, 0);
        distribute(cookies, k, v, result, 0, n);
        return result;
    }
};