class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        int n = grades.size();
        sort(grades.begin(), grades.end());
        
        int count = 0;
        int prev = 0;
        int sum = 0;
        int j = 0;
        
        for(int i=0; i<n ; i++) {
            if(i-j+1 > prev) {
                count++;
                prev = i-j+1;
                j = i+1;
            }
        }
        
        return count;
    }
};