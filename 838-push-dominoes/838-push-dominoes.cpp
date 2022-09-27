class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.length();
        
        for(int i=0 ; i<n ; i++) {
            
            if(i>0 && dominoes[i] == 'L' && dominoes[i-1] == '.') {
                if(i>1 && dominoes[i-2] == 'R') continue;
                int j = i-1;
                while(j>=0 && dominoes[j] == '.') dominoes[j--] = 'L';
            }
            else if(i<n-1 && dominoes[i] == 'R' && dominoes[i+1] == '.') {
                int j = i+1;
                while(j<n && dominoes[j] == '.') j++;
             
                if(j == n) {
                    while(i<n) dominoes[i++] = 'R';
                    break;
                }
                
                if(dominoes[j] == 'L') {
                    int k = j;
                    i++;
                    j--;
                    while(i < j) {
                        dominoes[i++] = 'R';
                        dominoes[j--] = 'L';
                    }
                    
                    i = k-1;
                }
                else if(dominoes[j] == 'R') {
                    while(i < j) dominoes[i++] = 'R';
                    i--;
                }
                
            }
            
        }
        
        return dominoes;
    }
};