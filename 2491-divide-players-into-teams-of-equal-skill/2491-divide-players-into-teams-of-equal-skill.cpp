class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size();
        if(n == 2) return skill[0] * skill[1];
        
        int totalSum = accumulate(skill.begin(), skill.end(), 0);
        int requiredTeams = n/2;
        
        if(totalSum % requiredTeams != 0) return -1;
        
        int sum = totalSum / requiredTeams;
        
        sort(skill.begin(), skill.end());
        long long ans = 0;
        int i = 0;
        int j = n-1;
        
        while(i < j) {
            if(skill[i] + skill[j] != sum) return -1;
            ans += skill[i] * skill[j];
            i++;
            j--;
        }
        
        return ans;
    }
};