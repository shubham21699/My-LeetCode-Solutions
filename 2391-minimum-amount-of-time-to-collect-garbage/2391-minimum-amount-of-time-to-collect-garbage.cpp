class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int n = garbage.size();
        int m = travel.size();
        
        int Mfreq=0, Pfreq=0, Gfreq=0;
        
        for(int i=0 ; i<n ; i++) {
            for(auto s : garbage[i]) {
                if(s == 'M') Mfreq++;
                else if(s == 'P') Pfreq++;
                else if(s == 'G') Gfreq++;
            }
        }
        
        int Mtime=0, Ptime=0, Gtime=0;
        
        for(int i=0 ; i<n ; i++) {
            for(auto s : garbage[i]) {
                if(s == 'M') {
                    Mtime++;
                    Mfreq--;
                }
            }
            
            if(Mfreq == 0) break;
            Mtime += travel[i];
        }
        
        for(int i=0 ; i<n ; i++) {
            for(auto s : garbage[i]) {
                if(s == 'P') {
                    Ptime++;
                    Pfreq--;
                }
            }
            
            if(Pfreq == 0) break;
            Ptime += travel[i];
        }
        
        for(int i=0 ; i<n ; i++) {
            for(auto s : garbage[i]) {
                if(s == 'G') {
                    Gtime++;
                    Gfreq--;
                }
            }
            
            if(Gfreq == 0) break;
            Gtime += travel[i];
        }
        
        return Mtime + Ptime + Gtime;
    }
};