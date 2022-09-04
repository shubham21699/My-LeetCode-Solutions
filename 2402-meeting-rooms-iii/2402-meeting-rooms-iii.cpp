class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        int m = meetings.size();
       
        sort(meetings.begin(), meetings.end());
        vector<int> freqOfUse(n);
        
        priority_queue<int, vector<int>, greater<int>> emptyRooms;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> endTimes;
        
        for(int i=0 ; i<n ; i++) {
            emptyRooms.push(i);
        }
        
        int j = 0;
        
        while(j < m) {
            
            int start = meetings[j][0];
            int end = meetings[j][1];
            
            while(endTimes.size() > 0 && endTimes.top().first <= start) {
                int room = endTimes.top().second;
                endTimes.pop();
                emptyRooms.push(room);
            }
            
            if(emptyRooms.size() > 0) {
                int room = emptyRooms.top();
                emptyRooms.pop();
                freqOfUse[room]++;
                endTimes.push({ end, room });
            }
            else {
                
                auto p = endTimes.top();
                endTimes.pop();
                
                freqOfUse[p.second]++;
                long long newEndTime = p.first + (end - start);
                
                endTimes.push({ newEndTime, p.second });
            }
            
            j++;
        }
        
        int ans = 0;
        int maxFreq = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(freqOfUse[i] > maxFreq) {
                maxFreq = freqOfUse[i];
                ans = i;
            }
        }
        
        return ans;
    }
};