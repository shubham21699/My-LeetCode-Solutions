class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        if(letters.back() <= target) return letters.front();
        
        int i = 0;
        int j = letters.size()-1;
        
        while(i < j) {
            
            int mid = i + (j-i)/2;
            
            if(letters[mid] > target) j = mid;
            else i = mid+1;
            
        }
        
        return letters[i];
    }
};