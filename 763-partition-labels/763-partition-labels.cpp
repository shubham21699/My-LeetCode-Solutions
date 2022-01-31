class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n = s.length();
        vector<int> result;
        
        unordered_map<char, int> m;
        for(int i=0 ; i<n ; i++) {
            m[s[i]] = i;
        }
        
        int index = 0;
        int length_so_far_used = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            index = max(index, m[s[i]]);
            
            if(index == i) {
                result.empty() ? result.push_back(i+1) : result.push_back(index - length_so_far_used + 1);
                length_so_far_used += result.back();
            }
            
        }
        
        return result;
    }
};