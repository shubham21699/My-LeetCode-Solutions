class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        if(str1 == str2) return str1;
        
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(n, m)) : "";
        
        
//         // OR:
//         string x = "";
        
//         for(int i=0 ; i<n && i<m ; i++) {
//             if(n % (i+1) != 0 || m % (i+1) != 0) continue;
            
//             string s = str1.substr(0, i+1);
//             bool flag = true;
            
//             for(int j=0 ; j<n-i ; j+=(i+1)) {
//                 if(str1.substr(j, i+1) != s) {
//                     flag = false;
//                     break;
//                 }
//             }
            
//             if(!flag) continue;
            
//             for(int j=0 ; j<m-i ; j+=(i+1)) {
//                 if(str2.substr(j, i+1) != s) {
//                     flag = false;
//                     break;
//                 }
//             }
                
//             if(flag) x = s;
//         }
        
//         return x;
    }
};