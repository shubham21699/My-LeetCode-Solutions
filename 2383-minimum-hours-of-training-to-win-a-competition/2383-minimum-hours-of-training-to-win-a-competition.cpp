class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        int n = energy.size();
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            if(initialEnergy > energy[i] && initialExperience > experience[i]) {
                initialEnergy -= energy[i];
                initialExperience += experience[i];
                continue;
            }
            if(initialEnergy <= energy[i]) {
                int x = energy[i] - initialEnergy;
                count += x+1;
                initialEnergy += x+1;
            }
            initialEnergy -= energy[i];
            
            if(initialExperience <= experience[i]) {
                int x = experience[i] - initialExperience;
                count += x+1;
                initialExperience += x+1;
            }
            initialExperience += experience[i];
            
        }
        
        return count;
    }
};