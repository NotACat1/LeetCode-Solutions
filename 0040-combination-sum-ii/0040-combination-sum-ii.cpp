#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(size_t start, int target, std::vector<int>& current, std::vector<int>& candidates, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (size_t i = start; i < candidates.size(); i++) {
            if (candidates[start] > target) break;

            if (i > start && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], current, candidates, result);
            current.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, current, candidates, result);
        return result;
    }
};