class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), m = edges.size();
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<vector<int>> count(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++) {
            count[i][colors[i] - 'a']++;
        }
        
        int max_count = 0;
        int visited = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;
            
            for(int i : adj[node]) {
                for(int j = 0; j < 26; j++) {
                    count[i][j] = max(count[i][j], count[node][j] + (colors[i] - 'a' == j ? 1 : 0));
                }
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
            max_count = max(max_count, *max_element(count[node].begin(), count[node].end()));
        }
        return (visited == n) ? max_count : -1;
    }
};

