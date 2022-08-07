class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        int n = tasks.size();
        unordered_map<int, long long> mp;
        
        long long days = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(mp.find(tasks[i]) != mp.end()) {
                long long prevOcc = mp[tasks[i]];
                long long curr = days;
                long long diff = curr - prevOcc;
                
                long long spaceToAdd = space - diff;
                if(spaceToAdd > 0) days += spaceToAdd;
                days++;
                
                mp[tasks[i]] = days;
            }
            else {
                days++;
                mp[tasks[i]] = days;
            }
            
        }
        
        return days;
    }
};