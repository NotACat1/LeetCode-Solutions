#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> answer(n, 0);
        std::stack<int> st;        

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDayIndex = st.top();
                st.pop();
                answer[prevDayIndex] = i - prevDayIndex;
            }
            st.push(i);
        }

        return answer;
    }
};