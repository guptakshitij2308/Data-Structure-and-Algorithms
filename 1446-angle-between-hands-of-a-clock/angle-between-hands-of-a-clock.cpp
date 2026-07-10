class Solution {
public:
    double angleClock(int hour, int minutes) {
        double totalHours=hour+(minutes/60.0);
        double hourAngle=totalHours*30;
        double minuteAngle=minutes*6.0;
        double diff=abs(hourAngle-minuteAngle);
        return min(diff,360-diff);
    }
};