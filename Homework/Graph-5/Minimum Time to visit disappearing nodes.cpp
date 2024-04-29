class Solution {
public:
    struct CompareDist {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    void dijkstra(vector<vector<pair<int, int>>>& graph, int start, vector<int>& dist, vector<int>& disappear) {
        int numNodes = graph.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDist> pq;

        dist.assign(numNodes, INT_MAX);
        dist[start] = 0;

        pq.push({start, 0});

        while (!pq.empty()) {
            int u = pq.top().first;
            int uDist = pq.top().second;
            pq.pop();

            if (uDist > dist[u]) continue;

            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v] && dist[u] + weight < disappear[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({v, dist[v]});
                }
            }
        }
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int l = edges[i][2];
            graph[u].push_back({v, l});
            graph[v].push_back({u, l});
        }

        vector<int> ans(n, INT_MAX);
        dijkstra(graph, 0, ans, disappear);
        for(int i=0;i<n;i++)
        {
            if(ans[i]==INT_MAX)
                ans[i]=-1;
}
        return ans;
    }
};
