class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();
        long long ans = 0;
        
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        if(nums == target) return 0;
        
        vector<int> odd, even, oddTar, evenTar;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
            
            if(target[i] % 2 == 0) evenTar.push_back(target[i]);
            else oddTar.push_back(target[i]);
        }
        
        for(int i=0 ; i<odd.size() ; i++) {
            ans += abs(oddTar[i] - odd[i]) / 2;
        }
        
        for(int i=0 ; i<even.size() ; i++) {
            ans += abs(evenTar[i] - even[i]) / 2;
        }
        
        return ans/2;
    }
};