class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        if(n <= 2) return n;
        
        unordered_map<int, int> mp;
        int maxFruits = 1;
        int i = 0;
        int j = 0;
        
        while(j < n) {
            
            mp[fruits[j]]++;
            
            while(mp.size() > 2) {
                mp[fruits[i]] == 1 ? mp.erase(fruits[i]) : mp[fruits[i]]--;
                i++;
            }
            
            maxFruits = max(maxFruits, j-i+1);
            j++;
        }
        
        return maxFruits;
    }
};