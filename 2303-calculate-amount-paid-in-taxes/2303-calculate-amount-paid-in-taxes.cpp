#include <vector>
#include <algorithm>

class Solution {
public:
    double calculateTax(std::vector<std::vector<int>>& brackets, int income) {
        if (income == 0) return 0.0;

        double totalTax = 0.0;
        int prevUpper = 0;

        for (const auto& bracket : brackets) {
            int upper = bracket[0];
            int percent = bracket[1];

            if (income > prevUpper) {
                int taxableAmount = std::min(income, upper) - prevUpper;
                
                totalTax += (double)taxableAmount * percent / 100.0;
                
                prevUpper = upper;
            } else {
                break;
            }
        }

        return totalTax;
    }
};