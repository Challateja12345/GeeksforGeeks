#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        int max_sum = 0, res = 0;

        // Row sums
        for (int i = 0; i < n; i++) {
            int sum_val = 0;
            for (int j = 0; j < n; j++) {
                sum_val += mat[i][j];
            }
            max_sum = max(max_sum, sum_val);
        }

        // Column sums
        for (int j = 0; j < n; j++) {
            int sum_val = 0;
            for (int i = 0; i < n; i++) {
                sum_val += mat[i][j];
            }
            max_sum = max(max_sum, sum_val);
        }

        // Calculate result
        for (int i = 0; i < n; i++) {
            int row_sum = 0;
            for (int j = 0; j < n; j++) {
                row_sum += mat[i][j];
            }
            res += max_sum - row_sum;
        }

        return res;
    }
};
