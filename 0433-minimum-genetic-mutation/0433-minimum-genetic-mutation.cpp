class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int n = bank.size();
        if(start == end) return 0;
        
        unordered_set<string> st(bank.begin(), bank.end());
        if(st.find(end) == st.end()) return -1;
        
        // Using BFS :-
        int mutations = 0;
        queue<string> q;
        q.push(start);
        
        while(!q.empty()) {
            
            int m = q.size();
            
            while(m > 0) {
                
                string s = q.front();
                q.pop();
                if(s == end) return mutations;
                
                st.erase(s);

                for(int i=0 ; i<8 ; i++) {
                    string t = s;
                    
                    t[i] = 'A';
                    if(st.find(t) != st.end()) q.push(t);
                    
                    t[i] = 'C';
                    if(st.find(t) != st.end()) q.push(t);
                    
                    t[i] = 'G';
                    if(st.find(t) != st.end()) q.push(t);
                    
                    t[i] = 'T';
                    if(st.find(t) != st.end()) q.push(t);
                }
                
                m--;
            }
            
            mutations++;
        }
        
        return -1;
    }
};