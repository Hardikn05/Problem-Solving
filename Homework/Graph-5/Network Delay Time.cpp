class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adj[u].push_back({v,time});
        }
        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        time[k]=0;
        while(!pq.empty())
        {
            auto [tim,node] = pq.top();
            pq.pop();
            for(auto [v,t]:adj[node])
            {
                if(time[v]>tim+t)
                {
                    time[v]=tim+t;
                    pq.push({tim+t,v});
                }
            }
        }
        int temp = INT_MIN;
        for(int i=1;i<time.size();i++)
        {
            cout<<time[i]<<" ";
            temp=max(temp,time[i]);
        }
        return temp==INT_MAX?-1:temp;
    }
};
