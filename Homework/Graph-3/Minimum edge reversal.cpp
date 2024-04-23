class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<int> adj[n+1],rev_adj[n+1];
            for(int i=0;i<edges.size();i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                rev_adj[edges[i][1]].push_back(edges[i][0]);
            }
            
          deque<pair<int,int>> dq;
          dq.push_front({src,0});
          vector<int> vis(n+1,0);
          while(!dq.empty())
          {
              int node = dq.front().first;
              int dis = dq.front().second;
              if(node == dst)
              return dis;
              vis[node]=1;
              dq.pop_front();
              for(auto i:adj[node])
              {
                  if(!vis[i])
                  {
        
                      dq.push_front({i,dis});
                  }
              }
              {
              for(auto i:rev_adj[node])
              {
                  if(!vis[i])
                  {
                      dq.push_back({i,dis+1});
                  }
              }
              }
          }
           return -1;
        }
};
