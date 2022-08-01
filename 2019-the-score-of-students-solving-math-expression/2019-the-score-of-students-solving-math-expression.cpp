class Solution {
public:
    unordered_set<int> calc(string& s, int i, int j, vector<vector<unordered_set<int>>>& dp) {
        
        unordered_set<int> st;
        
        if(i > j) return st;
        if(i == j) {
            st.insert(s[i]-'0');
            return st;
        }
        if(!dp[i][j].empty()) return dp[i][j];
        
        for(int k=i+1 ; k<j ; k+=2) {
            
            if(s[k] == '+' || s[k] == '*') {
                
                unordered_set<int> left = calc(s, i, k-1, dp);
                unordered_set<int> right = calc(s, k+1, j, dp);
                
                for(auto a : left) {
                    for(auto b : right) {
                        int val = 0;
                        
                        if(s[k] == '+') val = a + b;
                        else val = a * b;
                        
                        if(val > 1000) continue;
                        st.insert(val);
                    }
                }
                
            }
            
        }
        
        return dp[i][j] = st;
    }
    
    int originalAns(string& s) {
        
        vector<int> ans;
        int prod = 1;
        int n = s.length();
        
        for(int i=0 ; i<n ; i++) {
            
            if(s[i] == '+') {
                ans.push_back(prod);
                prod = 1;
            }
            else if(s[i] != '*') {
                prod *= (s[i] - '0');
            }
            
        }
        
        ans.push_back(prod);
        
        int total = 0;
        
        for(auto val : ans) {
            total += val;
        }
        
        return total;
    }
    
    int scoreOfStudents(string s, vector<int>& answers) {
        
        int n = s.length();
        int m = answers.size();
        
        if(n == 3) {
            
            int res = s[1] == '+' ? (s[0]-'0') + (s[2]-'0') : (s[0]-'0') * (s[2]-'0');
            int score = 0;
            
            for(int i=0 ; i<m ; i++) {
                if(answers[i] == res) score += 5;
            }
            
            return score;
        }
        
        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(n));
        unordered_set<int> wrongOrderedAns = calc(s, 0, n-1, dp);
        
        int original = originalAns(s);
        int score = 0;
        
        for(int i=0 ; i<m ; i++) {
            if(answers[i] == original) score += 5;
            else if(wrongOrderedAns.find(answers[i]) != wrongOrderedAns.end()) score += 2;
        }
        
        return score;
    }
};