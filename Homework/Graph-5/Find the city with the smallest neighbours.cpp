
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int limit) {
        vector<vector<int>> adj(n,vector<int>(n,(int)(1e4+7)));
        for(int i=0;i<n;i++)
        adj[i][i]=0;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int ans=-1;
        int c=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int f=0;
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]<=limit)
                count++;
            }
            if(c>=count){
                ans=i;
                c=count;
            }
        }
        return ans;
    }
};
