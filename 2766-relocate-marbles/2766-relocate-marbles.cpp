class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        
        int n = nums.size();
        int m = moveFrom.size();
        set<int> st(nums.begin(), nums.end());
        
        for(int i=0 ; i<m ; i++) {
            if(st.find(moveFrom[i]) != st.end()) {
                st.erase(moveFrom[i]);
                st.insert(moveTo[i]);
            }
        }
        
        vector<int> result;
        for(int x : st) result.push_back(x);
        
        return result;
    }
};