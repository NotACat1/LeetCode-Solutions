#include <vector>

class Solution {
private:
    void backtrack(int index, int remaining, std::vector<int>& current,
        std::vector<int>& candidates, std::vector<std::vector<int>>& result) {

        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        if (remaining < 0 || index == candidates.size()) {
            return;
        }

        current.push_back(candidates[index]);
        backtrack(index, remaining - candidates[index], current, candidates, result);

        current.pop_back();
        backtrack(index + 1, remaining, current, candidates, result);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;

        backtrack(0, target, currentCombination, candidates, result);

        return result;
    }
};