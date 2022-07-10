class Solution {
public:
    bool canChange(string start, string target) {
        
        if(start == target) return true;
        
        int k = start.size();
        int n = k;
        int m = target.size();
        
        if(n != m) return false;
        
        unordered_map<char, int> m1, m2;
        for(int i=0 ; i<n ; i++) m1[start[i]]++;
        for(int j=0 ; j<m ; j++) m2[target[j]]++;
        
        if(m1 != m2) return false;
        
        vector<int> st;
        for(int i=0 ; i<n ; i++) {
            if(start[i] == 'L' || start[i] == 'R') st.push_back(i);
        }
        
        vector<int> tar;
        for(int j=0 ; j<m ; j++) {
            if(target[j] == 'L' || target[j] == 'R') tar.push_back(j);
        }
        
        for(int i=0 ; i<st.size() ; i++) {
            if(start[st[i]] == target[tar[i]]) {
                if((start[st[i]] == 'L' && st[i] < tar[i]) || (start[st[i]] == 'R' && st[i] > tar[i]))
                    return false;
            }
            else return false;
        }
        
        return true;
    }
};