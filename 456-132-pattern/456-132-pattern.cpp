class Solution {
    bool check(vector<int>& nums, int index, int n, vector<int>& v) {
        
        if(v.size() == 3) {
            if(v[0] < v[2] && v[2] < v[1]) return true;
            return false;
        }
        
        bool flag = false;
        
        for(int i=index ; i<n ; i++) {
            v.push_back(nums[i]);
            flag = flag | check(nums, i+1, n, v);
            v.pop_back();
        }
        
        return flag;
    }
    
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3) return false;
        if(n == 3) {
            if(nums[0] < nums[2] && nums[2] < nums[1]) return true;
            return false;
        }
        
        stack<int> s;
        int s3 = INT_MIN;
        
        for(int i=n-1 ; i>=0 ; i--) {
            
            int s1 = nums[i];
            // s2 is the element present in stack.
            if(s1 < s3) return true;
            
            while(!s.empty() && s.top() < s1) {
                s3 = s.top();
                s.pop();
            }
            
            s.push(s1);
        }
        
        return false;
        
        // // OR: Will give TLE
        // vector<int> v;
        // return check(nums, 0, n, v);
    }
};