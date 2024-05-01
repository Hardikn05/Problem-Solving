class Solution {
public:
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, 1e7);
        vector<int> visited(n, -1);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (visited[node] == 1)
                continue;
            visited[node] = 1;
            for (auto [v, w] : adj[node]) {
                if (dist[v] > d + w) {
                   dist[v] = d + w;
                   pq.push({dist[v], v});
                }
            }
        }
        return dist;
}
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> src = dijkstra(n, adj, 0);
        vector<int> dst = dijkstra(n, adj, n - 1);
        int e = edges.size(), shortest = src[n - 1];
        vector<bool> ans(e, false);
        for (int i = 0; i < e; i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if ((src[u] + dst[v] + w == shortest) || (src[v] + dst[u] + w == shortest))
                ans[i] = true;
        }
        return ans;
    }
};
