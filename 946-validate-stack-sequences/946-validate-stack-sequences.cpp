class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        stack<int> s;
        int index = 0;
        
        for(int i=0 ; i<n && index<n ; i++) {
            s.push(pushed[i]);
            while(!s.empty() && index<n && s.top() == popped[index]) {
                s.pop();
                index++;
            }
        }
        
        if(!s.empty()) return false;
        return true;
    }
};