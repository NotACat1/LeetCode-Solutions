#include <string>
#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    int daysBetweenDates(std::string date1, std::string date2) {
        return std::abs(daysFromEpoch(date1) - daysFromEpoch(date2));
    }

private:
    int countLeapYears(const int year) {
        return year / 4 - year / 100 + year / 400;
    }

    bool isLeap(const int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    std::vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int daysFromEpoch(std::string date) {
        int year  = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day   = std::stoi(date.substr(8, 2));

        long days = (year - 1) * 365L + countLeapYears(year - 1);

        for (int m = 0; m < month - 1; m++) {
            days += daysInMonth[m];
            if (m == 1 && isLeap(year)) {
                days += 1;
            }
        }

        days += day;

        return (int)days;
    }
};