class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        // The minute hand moves 360 degrees in 60 minute(or 6 degrees in one minute) and 
        // hour hand moves 360 degrees in 12 hours(or 0.5 degrees in 1 minute). 
        // In h hours and m minutes, the minute hand would move (h*60 + m)*6 and hour hand 
        // would move (h*60 + m)*0.5. 
        
        if(hour == 12) hour = 0;
        if(minutes == 60) {
            minutes = 0;
            hour++;
            if(hour > 12) hour = hour-12;
        }
        
        // Calculate the angles moved by hour and minute hands with reference to 12:00
        double hour_angle = (hour*60 + minutes) * 0.5;
        double minutes_angle = minutes * 6;
        
        // Find the difference between two angles
        double angle = abs(hour_angle - minutes_angle);
        
        // Return the smaller angle of two possible angles
        double min_angle = min(360 - angle, angle);
        return min_angle;
    }
};