#include <vector>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        if (s.empty()) return;

        size_t left = 0;
        size_t right = s.size() - 1;

        while (left < right) {
            std::swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};