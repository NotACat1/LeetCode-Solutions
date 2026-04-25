#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        if (s.empty()) return s;

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            if (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        char lowerC = std::tolower(static_cast<unsigned char>(c));
        return vowelLetters.contains(lowerC);
    }

    std::unordered_set<char> vowelLetters = { 'a', 'e', 'i', 'o', 'u' };
};