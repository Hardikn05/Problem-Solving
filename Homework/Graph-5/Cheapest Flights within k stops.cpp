class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adj[u].push_back({v, price});
        }
        k++;
        vector<int> distance(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, src});
        
        while(pq.size())
        {
            int stops=pq.top()[0];
            int dis=pq.top()[1];
            int node=pq.top()[2];
            pq.pop();
            if(stops>=k)continue;
            for(auto it:adj[node])
            {
                if(distance[it.first]>dis+it.second)
                {
                    distance[it.first]=dis+it.second;
                    pq.push({stops+1,distance[it.first],it.first});
                }
            }
        }
              return distance[dst]==INT_MAX?-1:distance[dst];
    }
};
