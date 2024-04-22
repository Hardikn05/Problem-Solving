class Solution {
public:
    bool dfs(int i,vector<bool> &visited,vector<vector<int>> &adj,vector<bool> &path)
    {
        visited[i]=1;
        path[i]=1;
        for(auto it:adj[i])
        {
            if(!visited[it])
            {
                if(dfs(it,visited,adj,path)==false)
                return false;
            }
            else if(path[it])
            return false;
        }
        path[i]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pq) {
         vector<vector<int>> adj(numCourses);
         for(int i=0;i<pq.size();i++){
             int u = pq[i][0];
             int v = pq[i][1];

             adj[v].push_back(u);
         }
         vector<bool> visited(numCourses);
         vector<bool> path(numCourses);

         for(int i=0;i<numCourses;i++)
         {
             if(!visited[i])
             {
                if(!dfs(i,visited,adj,path))
                {
                    return false;
                }
             }
         }
     return true;    
    }
};
