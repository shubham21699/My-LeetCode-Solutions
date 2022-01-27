class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        if(n <= 1) return true;
        
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses);
        
        for(int i=0 ; i<n ; i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int count = 0; // Counts number of unique non-repeating courses
    
        while(!q.empty()) {
            
            int current = q.front();
            q.pop();
            count++;
            
            for(auto nextCourse : graph[current]) {
                if(--indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
            
        }
        
        if(count == numCourses) return true; 
        return false; // Means Cycle Exists
        
    }
};