class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &path)
    {
      vis[i]=1;
      path[i]=1;
       for(auto it:adj[i])
       {
           if(!vis[it])
           {
               if(dfs(it,adj,vis,path))
               return true;
           }
           else if(path[it]){
               return true;
           }
       }
       path[i]=0;
       return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,path))
                return true;
            }
        }
        return false;
    }
};
