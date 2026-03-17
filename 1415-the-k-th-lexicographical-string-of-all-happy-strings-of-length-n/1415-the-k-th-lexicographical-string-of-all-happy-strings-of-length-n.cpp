#include <string>

class Solution {
public:
    std::string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total) return "";

        std::string ans = "";
        char prev = '#';

        for (int i = 0; i < n; ++i) {
            for (char c : {'a', 'b', 'c'}) {
                if (c == prev) continue;

                int remaining = n - i - 1;
                int cnt = 1 << remaining;

                if (k > cnt) {
                    k -= cnt;
                }
                else {
                    ans += c;
                    prev = c;
                    break;
                }
            }
        }

        return ans;
    }
};