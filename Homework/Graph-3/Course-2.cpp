class Solution {
public:
    bool dfs(vector<bool> &vis,int i,vector<bool> &path,stack<int> &s,vector<int> adj[]){
        vis[i]=1;
        path[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(vis,it,path,s,adj)==false)
                return false;
            }
            else if(path[it])
            return false;
        }
        path[i]=0;
        s.push(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses),path(numCourses);
        stack<int> s;
        bool ans = true;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(!dfs(vis,i,path,s,adj))
                {
                    ans=false;
                    break;
                }
            }
        }
        if(ans)
        {
            while(!s.empty())
            {
                ret.push_back(s.top());
                s.pop();
            }
        }
        return ret;
    }
};
