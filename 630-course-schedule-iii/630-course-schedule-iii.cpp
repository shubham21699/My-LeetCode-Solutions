class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int n = courses.size();
        if(n == 1) return courses[0][0] <= courses[0][1] ? 1 : 0;
        
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        int time = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(time + courses[i][0] <= courses[i][1]) {
                time += courses[i][0];
                pq.push(courses[i][0]);
            }
            else if(!pq.empty() && pq.top() > courses[i][0]) {
                time += courses[i][0] - pq.top();
                pq.pop(); 
                pq.push(courses[i][0]);
            }
        }
    
        return pq.size();
    }
};