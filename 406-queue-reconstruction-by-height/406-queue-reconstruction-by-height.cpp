class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int n = people.size();
        if(n == 1) return people;
        
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
            
        });
        
        vector<vector<int>> result;
        
        for(int i=0 ; i<n ; i++) {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        
        return result;
    }
};