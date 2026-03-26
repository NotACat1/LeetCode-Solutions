#include <cmath>

class Solution {
public:
    int countTriples(int n) {
		int count = 0;

		for (size_t a = 1; a < n; ++a)
		{
			for (size_t b = 1; b < n; ++b)
			{
				auto sum = a * a + b * b;
				int c = std::sqrt(sum);

				if (c <= n && c * c == sum) {
					++count;
				}
			}
		}

		return count;
    }
};