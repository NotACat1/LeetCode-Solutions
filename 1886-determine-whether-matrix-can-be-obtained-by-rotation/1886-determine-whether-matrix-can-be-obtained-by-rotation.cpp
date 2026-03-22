#include <vector>
#include <algorithm>

class Solution {
public:
    using Matrix = std::vector<std::vector<int>>;

    bool findRotation(Matrix& mat, const Matrix& target) {
        for (int k = 0; k < 4; ++k) {
            if (isEqual(mat, target)) {
                return true;
            }
            rotate90(mat);
        }
        return false;
    }

private:
    static bool isEqual(const Matrix& a, const Matrix& b) noexcept {
        const size_t n = a.size();

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (a[i][j] != b[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    static void rotate90(Matrix& m) noexcept {
        const size_t n = m.size();

        // 1) Transpose
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                std::swap(m[i][j], m[j][i]);
            }
        }

        // 2) Reverse each row
        for (auto& row : m) {
            std::reverse(row.begin(), row.end());
        }
    }
};