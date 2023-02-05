class Solution {
public:
    int isVowel(char ch) {
    
        string str = "aeiou";
        
        return (str.find(ch) != string::npos);
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();
        int q = queries.size();
        
        vector<int> isVowelString(n);
        for(int i=0 ; i<n ; i++) {
            if(isVowel(words[i][0]) && isVowel(words[i].back())) isVowelString[i] = 1;
            
            if(i > 0) isVowelString[i] += isVowelString[i-1];
        }
        
        vector<int> result(q);
        
        for(int i=0 ; i<q ; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            
            result[i] = start == 0 ? isVowelString[end] : isVowelString[end] - isVowelString[start-1];
        }
        
        return result;
    }
};