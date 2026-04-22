#include <string>
#include <vector>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n <= 0) return "";
        if (n == 1) return "1";

        std::string res = "1";

        for (int i = 2; i <= n; ++i) {
            std::string next_res = "";
            int len = res.length();

            for (int j = 0; j < len; ++j) {
                int count = 1;
                while (j + 1 < len && res[j] == res[j + 1]) {
                    count++;
                    j++;
                }
                next_res += std::to_string(count) + res[j];
            }
            res = next_res;
        }

        return res;
    }
};