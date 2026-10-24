class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Number of days in each month for a non-leap year
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Lambda function to convert "MM-DD" to day of the year
        auto convertToDayOfYear = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };
        
        int aArrival = convertToDayOfYear(arriveAlice);
        int aLeave = convertToDayOfYear(leaveAlice);
        int bArrival = convertToDayOfYear(arriveBob);
        int bLeave = convertToDayOfYear(leaveBob);
        
        // Find the start and end of the overlapping period
        int overlapStart = max(aArrival, bArrival);
        int overlapEnd = min(aLeave, bLeave);
        
        // If overlapStart <= overlapEnd, they spent time together
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0;
    }
};