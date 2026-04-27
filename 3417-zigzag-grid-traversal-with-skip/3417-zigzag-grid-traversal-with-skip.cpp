#include <vector>

using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int m = grid.size();
        int n = grid[0].size();
        
        bool should_keep = true;

        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; ++j) {
                    if (should_keep) {
                        result.push_back(grid[i][j]);
                    }
                    should_keep = !should_keep;
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    if (should_keep) {
                        result.push_back(grid[i][j]);
                    }
                    should_keep = !should_keep; 
                }
            }
        }
        
        return result;
    }
};