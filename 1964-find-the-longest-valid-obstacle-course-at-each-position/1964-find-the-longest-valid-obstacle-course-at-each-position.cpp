class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int n = obstacles.size();
        int length = 0;
        vector<int> result(n);
        vector<int> incSubSeq(n);
        
        for(int i=0 ; i<n ;i ++) {
            
            int left = 0, right = length;
            
            while(left < right) {
                
                int mid = left + (right - left)/2;
                
                if(incSubSeq[mid] <= obstacles[i]) left = mid+1;
                else right = mid;
                
            }
            
            result[i] = left+1;
            
            if(length == left) length++;
            incSubSeq[left] = obstacles[i];
        }
        
        return result;
    }
};