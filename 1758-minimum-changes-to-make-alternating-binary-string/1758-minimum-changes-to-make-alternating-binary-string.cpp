class Solution {
public:
    int minOperations(std::string s) {
        int count1 = 0; // 010101...
        int count2 = 0; // 101010...

        for (int i = 0; i < s.length(); ++i) {
            if (i % 2 == 0) {
                if (s[i] != '0') count1++;
                if (s[i] != '1') count2++;
            }
            else {
                if (s[i] != '1') count1++;
                if (s[i] != '0') count2++;
            }
        }

        return std::min(count1, count2);
    }
};