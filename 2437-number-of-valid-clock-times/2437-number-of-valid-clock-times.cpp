class Solution {
public:
    int countTime(string time) {
        
        int countHr = 1, countMin = 1;
        
        // For Hours
        if(time.substr(0, 2) == "??") countHr = 24;
        else if(time[0] == '?') {
            if(time[1] >= '4') countHr = 2;
            else countHr = 3;
        }
        else if(time[1] == '?') {
            if(time[0] == '2') countHr = 4;
            else countHr = 10;
        }
        
        // For Minutes
        if(time.substr(3, 2) == "??") countMin = 60;
        else if(time[4] == '?') countMin = 10;
        else if(time[3] == '?') countMin = 6;
        
        return countHr * countMin;
    }
};