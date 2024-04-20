#include <bits/stdc++.h>

   int Solution::knight(int rows, int cols, int startRow, int startCol, int targetRow, int targetCol) {
        vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
        vector<int> dy = {1, -1, 2, -2, 2, -2, 1, -1};
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({startRow, startCol});
        visited.insert({startRow, startCol});
        int distance = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first;
                int y = q.front().second;
                if (x == targetRow && y == targetCol)
                    return distance;
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int nextX = x + dx[i];
                    int nextY = y + dy[i];
                    if (nextX >= 1 && nextY >= 1 && nextX <= rows && nextY <= cols) {
                        if (visited.find({nextX, nextY}) == visited.end()) {
                            visited.insert({nextX, nextY});
                            q.push({nextX, nextY});
                        }
                    }
                }
            }
            distance++;
        }
        return -1;
    }
