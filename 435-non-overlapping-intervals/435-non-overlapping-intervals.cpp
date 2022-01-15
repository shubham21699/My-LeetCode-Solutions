class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end());
        intervals.erase(unique(intervals.begin(), intervals.end()), intervals.end());
        
        int count = n - intervals.size();
        n = intervals.size();
        
        if(n == 1) return count;
        
        stack<vector<int> > s;
        s.push(intervals[0]);
        
        for(int i=1 ; i<n ; i++) {
            if(intervals[i][0] >= s.top()[1]) {
                s.push(intervals[i]);
            }
            else {
                count++;
                if(intervals[i][1] < s.top()[1]) {
                    s.pop();
                    s.push(intervals[i]);
                }
            }
        }
        
        return count;
    }
};