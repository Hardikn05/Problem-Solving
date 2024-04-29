class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        vector<double> distance(n,DBL_MIN);
        priority_queue<pair<double,int>> pq;
        pq.push({1.00,start_node});
        distance[start_node]=1;
        while(!pq.empty())
        {
            auto [prob,node] = pq.top();
            pq.pop();

            for(auto [v,p]:adj[node])
            {
                if(distance[v]<prob*p)
                {
                    distance[v]=prob*p;
                    pq.push({prob*p,v});
                }
            }
        }
        return distance[end_node]==DBL_MIN?0:distance[end_node];
    }
};
