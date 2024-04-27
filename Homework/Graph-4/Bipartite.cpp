class Solution {
public:
    bool bfs(vector<vector<int>> graph,vector<int> &color,int i)
    {
        color[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(color[it]==-1){
                q.push(it);
                color[it]=!color[node];
                }
                if(color[node]==color[it])
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        int ik=0;
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(graph,color,i))
                {
                    ik=1;
                    break;
                }
            }
        }
        return ik!=1;
    }
};
