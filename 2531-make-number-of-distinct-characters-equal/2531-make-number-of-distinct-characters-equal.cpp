class Solution {
public:
    bool isItPossible(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        unordered_map<char, int> freq1, freq2;
        
        for(int i=0 ; i<n ; i++) freq1[word1[i]]++;
        for(int j=0 ; j<m ; j++) freq2[word2[j]]++;
        
        int count1 = 0, count2 = 0;
        for(int i=0 ; i<26 ; i++) {
            if(freq1['a'+i] > 0) count1++;
            if(freq2['a'+i] > 0) count2++;
        }
        
        if(count1 == count2 && n == m) return true;
        
        for(int i=0 ; i<26 ; i++) {
            
            if(freq1['a'+i] > 0) {
                
                for(int j=0 ; j<26 ; j++) {
                    
                    if(freq2['a'+j] > 0) { 
                        
                        if(i == j) {
                            if(count1 == count2) return true;
                        }
                        else {
                        
                            int f1 = count1;
                            int f2 = count2;

                            if(freq1['a'+i] == 1) f1--;
                            if(freq1['a'+j] == 0) f1++;

                            if(freq2['a'+j] == 1) f2--;
                            if(freq2['a'+i] == 0) f2++;

                            if(f1 == f2) return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};