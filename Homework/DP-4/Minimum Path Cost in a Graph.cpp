class Solution {
public:
    int Memoization(vector<vector<int>> &grid, vector<vector<int>> &moveCost, int i, int j, vector<vector<int>> &dp) {
        if (i == grid.size() - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;
        for (int k = 0; k < grid[0].size(); k++) {
            ans = min(ans, grid[i][j] + moveCost[grid[i][j]][k] + Memoization(grid, moveCost, i + 1, k, dp));
        }

        dp[i][j] = ans;
        return ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int j = 0; j < grid[0].size(); j++) {
            ans = min(ans, Memoization(grid, moveCost, 0, j, dp));
        }

        return ans;
    }
};
