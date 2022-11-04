class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.size();
        int i = 0;
        int j = n-1;
        
        while(i < j) {
            /*
            The std::string::find_first_of is a string class member function which is used to find the index of 
            first occurrence of any characters in a string. If the character is present in the string then it
            returns the index of the first occurrence of that character in the string else it returns
            string::npos.
            The std::string::find_last_of is a string class member function which is used to find the index of
            last occurrence of any characters in a string. If the character is present in the string then it 
            returns the index of the last occurrence of that character in the string else it returns
            string::npos.
            */
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            
            if(i < j) swap(s[i++], s[j--]);
        }
        
        return s;
        
        
//         // OR:
//         stack<char> st;
        
//         for(int i=0 ; i<n ; i++) {
//             if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
//                 st.push(s[i]);
//             }
//         }
        
//         for(int i=0 ; i<n ; i++) {
//             if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
//                 s[i] = st.top();
//                 st.pop();
//             }
//         }
        
//         return s;
    }
};