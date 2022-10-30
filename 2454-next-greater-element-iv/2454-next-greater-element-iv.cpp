class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n, -1);
        
        if(n < 3) return result;
        
        // s1 stores the index of elements that have not found their 1st greater element.
        // s2 stores the index of elements that have found their 1st greater element but not 2nd greater element.
        stack<int> s1, s2;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!s2.empty() && nums[s2.top()] < nums[i]) {
                result[s2.top()] = nums[i];
                s2.pop();
            }
            
            stack<int> temp;
            while(!s1.empty() && nums[s1.top()] < nums[i]) {
                temp.push(s1.top());
                s1.pop();
            }
            
            while(!temp.empty()) {
                s2.push(temp.top());
                temp.pop();
            }
            
            s1.push(i);
        }
        
        return result;
    }
};