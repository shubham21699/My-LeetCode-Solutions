/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        int n = employees.size();
        unordered_map<int, int> imp;
        map<int, vector<int>> graph;
        
        for(int i=0 ; i<n ; i++) {
            graph[employees[i]->id] = employees[i]->subordinates;
            imp[employees[i]->id] = employees[i]->importance;
        }
        
        int importance = imp[id];
        int size = graph[id].size();
        queue<int> q;
        
        for(int i=0 ; i<size ; i++) {
            q.push(graph[id][i]);
        }
        
        while(!q.empty()) {
            
            importance += imp[q.front()];
            int j = graph[q.front()].size();
            vector<int> v = graph[q.front()];
            q.pop();
            
            for(int k=0 ; k<j ; k++) {
                q.push(v[k]);
            }
            
        }
        
        return importance;
    }
};