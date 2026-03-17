#include <vector>
#include <cmath>

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, std::vector<int>& workerTimes) {
        long long left = 0;
        long long right = 1e18;

        while (left < right) {
            long long mid = (left + right) / 2;

            if (can(mid, mountainHeight, workerTimes))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

private:
    bool can(long long T, int H, const std::vector<int>& times) {
        long long total = 0;

        for (long long t : times) {
            // t*x(x+1)/2 ≤ T
            long double D = 1.0L + 8.0L * T / t;
            long long x = (std::sqrt(D) - 1) / 2;

            total += x;

            if (total >= H) return true;
        }

        return false;
    }
};