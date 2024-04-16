class Solution {
public:
    bool dfs(vector<int> adj[],vector<bool> &vis,int source,int destination)
    {
        if(source==destination)
        return true;

        vis[source] = true;

        bool ans = false;
        for(int i=0;i<adj[source].size();i++)
        {
            if(!vis[adj[source][i]])
            {
                ans = ans || dfs(adj,vis,adj[source][i],destination);
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        return dfs(adj,vis,source,destination);
    }
};
