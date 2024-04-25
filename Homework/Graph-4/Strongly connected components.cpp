lass Solution
{
public:
    
    // Function to find number of strongly connected components in the graph.
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& stack)
    {
        if (visited[node] == 1)
            return;
        visited[node] = 1;
        for (auto i : adj[node])
            dfs(i, adj, visited, stack);
        stack.push(node);
    }
    
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited)
    {
        if (visited[node] == 1)
            return;
        visited[node] = 1;
        for (auto i : adj[node])
            dfs(i, adj, visited);
    }
    
    
    int kosaraju(int V, vector<vector<int>>& adjacencyList)
    {
        stack<int> stack;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
                dfs(i, adjacencyList, visited, stack);
        }
        
        vector<vector<int>> T_adj(V);
        for (int i = 0; i < V; i++)
        {
            for (auto j : adjacencyList[i])
                T_adj[j].push_back(i);
        }
        
        for (int i = 0; i < V; i++)
            visited[i] = 0;
        
        int count = 0;
        while (!stack.empty())
        {
            int node = stack.top();
            stack.pop();
            if (visited[node] == 0)
            {
                dfs(node, T_adj, visited);
                count++;
            }
        }
        return count;
    }
};
