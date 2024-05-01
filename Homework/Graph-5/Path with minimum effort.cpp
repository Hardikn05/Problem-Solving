class Solution {
public:
    int solve(vector<vector<int>>& h, vector<vector<int>> p, vector<vector<int>>& d) {
        int n = h.size();
        int m = h[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        d[0][0] = 0;
        q.push({0, 0, 0});
        while (!q.empty()) {
            int i = q.top()[1];
            int j = q.top()[2];
            int cur_e = q.top()[0];
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = p[k][0] + i;
                int y = p[k][1] + j;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int e = max(cur_e, abs(h[x][y] - h[i][j]));
                    if (d[x][y] > e) {
                        d[x][y] = e;
                        q.push({d[x][y], x, y});
                    }
                }
            }
        }
        return d[n - 1][m - 1];
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> path = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        return solve(heights, path, dis);
    }
};
