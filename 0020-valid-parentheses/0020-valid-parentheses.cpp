#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.empty()) return true;

        std::stack<char> st;
        std::unordered_map<char, char> matching = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (const auto& ch : s) {
            if (matching.count(ch)) {
                if (st.empty() || st.top() != matching[ch]) {
                    return false;
                }
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        return st.empty();
    }
};
