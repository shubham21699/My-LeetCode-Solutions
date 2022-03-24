class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int n = people.size();
        sort(people.begin(), people.end());
        
        int boats = 0;
        int i = 0;
        int j = n-1;
        
        while(j >= 0 && i <= j) {
            
            if(people[i] + people[j] <= limit) {
                i++;
            }
            
            boats++;
            j--;
            
        }
        
        return boats;
    }
};