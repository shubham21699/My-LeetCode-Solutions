class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n = arr.size();
        unordered_map<int, int > mp;
        long long int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            count = (count + mp[target - arr[i]]) % 1000000007;
            for(int j=0 ; j<i ; j++) {
                mp[arr[i]+arr[j]]++;
            }
        }
        
        return count;
    }
};