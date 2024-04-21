#include <bits/stdc++.h>
int dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int& maxLength) {
    int curr = 0;
    visited[node] = 1;
    for (auto adjacentNode : adj[node]) {
        if (visited[adjacentNode] == -1) {
            int distance = dfs(adjacentNode, adj, visited, maxLength);
            maxLength = max(maxLength, curr + distance);
            curr = max(curr, distance);
        }
    }
    maxLength = max(maxLength, curr);
    return curr + 1;
}

int Solution::solve(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> adj(n);
    int root;
    for (int i = 0; i < n; i++) {
        if (A[i] == -1)
            root = i;
        else {
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
    }
    vector<int> visited(n, -1);
    int mx = 0;
    dfs(root, adj, visited, mx);
    return mx;
}
