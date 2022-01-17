class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        vector<int> result;
        vector<int> indegree(numCourses); // indegree[i] denotes no. of prerequisite courses for ith course
        vector<vector<int> > graph(numCourses); // prerequisite-course: [list of next courses]
        
        // Forming adjacency list graph
        for(auto& pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++) {
            if(indegree[i] == 0) {
                q.push(i); // We can start with courses having no prerequisites
            }
        }
        
        while(!q.empty()) {
            
            int current = q.front();
            q.pop();
            result.push_back(current); // current has no prerequisites now so we can take it
            
            for(auto nextCourse : graph[current]) {
                // If there is a next course having 0 prerequisite remaining, then we can now take it
                if(--indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
            
        }
        
        if(result.size() == numCourses) return result;
        return {};
    }
};