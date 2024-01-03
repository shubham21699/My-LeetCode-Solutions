class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n = bank.size();
        int m = bank[0].length();
        if(n == 1) return 0;
        
        vector<int> beams;
        
        for(int i=0 ; i<n ; i++) {
            int count = 0;
            for(int j=0 ; j<m ; j++) {
                if(bank[i][j] == '1') count++;
            }
            
            // If there is no security device in a row we skip it as it will not generate any beam.
            if(count > 0) beams.push_back(count);
        }
        
        if(beams.size() == 0) return 0;
        
        int result = 0;
        
        for(int i=0 ; i<beams.size()-1 ; i++) {
            // Adding number of beams between 2 rows having security devices.
            result += beams[i] * beams[i+1];
        }
        
        return result;
    }
};