class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int m = target.size();
        vector<string> result;
        int j = 0;
        
        for(int i=1 ; i<=n && j<m ; i++) {
            if(target[j] == i) {
                result.push_back("Push");
                j++;
            }
            else {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        
        return result;
    }
};