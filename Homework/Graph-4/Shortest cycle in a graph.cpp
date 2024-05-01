class Solution {
public:
    int bfs(int src, int dest, vector<unordered_set<int>>& adj) {
        queue<int> q;
        vector<int> v(adj.size(), 0);
        v[src] = 1;
        q.push(src);
        int l = 1;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int f = q.front();
                q.pop();
                if (f == dest) return l;
                for (auto x : adj[f]) {
                    if (!v[x]) {
                        v[x] = 1;
                        q.push(x);
                    }
                }
            }
            l++;
        }
        return INT_MAX;
    }
    int findShortestCycle(int n, vector<vector<int>>& e) {
        vector<unordered_set<int>> adj(n);
        for (auto x : e) {
            adj[x[0]].insert(x[1]);
            adj[x[1]].insert(x[0]);
        }
        int min_len = INT_MAX;
        for (int i = 0; i < e.size(); i++) {
            int u = e[i][0], v = e[i][1];
            adj[u].erase(v);
            adj[v].erase(u);
            min_len = min(min_len, bfs(u, v, adj));
            adj[u].insert(v);
            adj[v].insert(u);
        }
        if (min_len == INT_MAX) return -1;
        return min_len;
    }
};
