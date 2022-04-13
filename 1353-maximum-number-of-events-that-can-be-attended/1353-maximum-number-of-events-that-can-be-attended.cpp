class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        if(n == 1) return 1;
        
        // Sort the events according to their startTime.
        sort(events.begin(), events.end());
        
        // Priority queue contains deadlines of all the events that have already started but not ended.
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0;
        int i = 0;
        
        for(int day=1 ; day<=100000 ; day++) {
            
            // Remove all the events that are already over.
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // Insert deadlines of all events that start today.
            while(i<n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            
            // If there is any event that we can attend today we attend the event with smallest endTime.
            if(!pq.empty()) {
                pq.pop();
                count++;
            }
            
            // If all the events are processed, then stop
            if(pq.empty() && i==n) {
                break;
            }
            
        }
        
        return count;
    }
};