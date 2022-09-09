class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        int n = properties.size();
        sort(properties.begin(), properties.end(), [] (vector<int>& a, vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        int count = 0;
        stack<pair<int, int>> st;
        
        for(int i=0 ; i<n ; i++) {
            
            while(!st.empty() && st.top().first < properties[i][0] && st.top().second < properties[i][1]) {
                st.pop();
                count++;
            }
            
            st.push({ properties[i][0], properties[i][1] });
        }
        
        return count;
    }
};