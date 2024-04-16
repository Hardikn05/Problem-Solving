class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int> &vis,int node)
    {
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++)
        {
            if(vis[i]==-1 && isConnected[node][i]==1)
            dfs(isConnected,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),-1);
        int ans=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(vis[i]==-1)
            {
                ans+=1;
                dfs(isConnected,vis,i);
            }
        }
        return ans;
    }
};
