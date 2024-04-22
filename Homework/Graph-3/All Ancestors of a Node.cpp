class Solution {
public:
    void dfs(vector<int> adj[],vector<int> &vis,int source,int node,vector<set<int>> &ans)
    {
        vis[node] = 1;
        for(auto i:adj[node])
        {
            if(!vis[i])
            dfs(adj,vis,source,i,ans);
        }
        ans[node].insert(source);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for(int i=0;i<n;i++)
        {
            vector<int> vis(n,0);
            for(auto j:adj[i])
            {
              dfs(adj,vis,i,j,ans);
            }    
        }

        vector<vector<int>> fin(n);
        for(int i=0;i<n;i++)
        {
            for(auto j:ans[i])
            {
               fin[i].push_back(j);
            }
        }
        return fin;
    }
};
