class Solution {
public:
    bool check(string result, string pattern) {
        
        for(int i=0 ; i<pattern.length() ; i++) {
            if(pattern[i] == 'I' && result[i] >= result[i+1]) return false;
            if(pattern[i] == 'D' && result[i] <= result[i+1]) return false;
        }
        
        return true;
    }
    
    string smallestNumber(string pattern) {
        
        int n = pattern.size();
        string result = "";
        
        stack<int> st;
        
        for(int i=0 ; i<=n ; i++) {
            
            st.push(i+1);
            
            if(pattern[i] == 'I' || i == n) {
                while(!st.empty()) {
                    result += st.top()+'0';
                    st.pop();
                }
            }
            
        }
        
        return result;
        
        
//         // OR:
//         int n = pattern.size();
//         string result = "";
        
//         for(int i=1 ; i<=n+1 ; i++) result += i+'0';
        
//         do {
            
//             if(check(result, pattern)) break;
            
//         } while(next_permutation(result.begin(), result.end()));
        
//         return result;
        
        
//         // OR:
//         int n = pattern.length();
//         int mini = 1;
//         int maxi = n+1;
//         int minPos = 0;
        
//         string result = "";
        
//         if(pattern[0] == 'I') {
//             result.push_back('1');
//             result.push_back('2');
//             mini = 3;
//             minPos = 1;
//         }
//         else {
//             result.push_back('2');
//             result.push_back('1');
//             mini = 3;
//             minPos = 0;
//         }
        
//         for(int i=1 ; i<n ; i++) {
            
//             if(pattern[i] == 'I') {
//                 result.push_back(mini+'0');
//                 mini++;
//                 minPos = i+1;
//             }
//             else {
//                 result.push_back(result.back());
                
//                 for(int j=minPos ; j<=i ; j++) {
//                     int val = result[j]-'0';
//                     result[j] = (val+1)+'0';
//                 }
                
//                 mini++;
//             }
            
//         }
        
//         return result;
    }
};