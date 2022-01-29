class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return { nums[0] };
        
        unordered_map<int, int> m;
        vector<int> result;
        priority_queue<pair<int, int>> p;
        
        for(int i=0 ; i<n ; i++) m[nums[i]]++;
        
        for(auto it=m.begin() ; it!=m.end() ; it++) p.push({ it->second, it->first });
        
        while(k--) {
            result.push_back(p.top().second);
            p.pop();
        }
        
        return result;
    }
};