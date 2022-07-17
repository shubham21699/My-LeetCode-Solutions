class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int n = nums.size();
        int m = numsDivide.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        unordered_set<int> s;
        
        for(int i=0 ; i<n ; i++) {
            if(s.find(nums[i]) == s.end()) {
                pq.push(nums[i]);
                s.insert(nums[i]);
            }
            mp[nums[i]]++;
        }
        
        int count = 0;
        
        while(!pq.empty()) {
            
            int x = pq.top();
            bool flag = true;
            
            for(int i=0 ; i<m ; i++) {
                if(numsDivide[i] % x != 0) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) return count;
            
            pq.pop();
            count += mp[x];
            
        }
        
        return -1;
    }
};