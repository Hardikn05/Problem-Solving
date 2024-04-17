class Solution {
public:
    void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j)
    {
        vis[i][j]=1;

        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size())
{
        if(j+1<grid[0].size() && vis[i][j+1]==0 && grid[i][j+1]=='1')
        {
            dfs(grid,vis,i,j+1);
        }
        if(i+1<grid.size() && vis[i+1][j]==0 && grid[i+1][j]=='1')
        {
            dfs(grid,vis,i+1,j);
        }
        if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]=='1')
        {
            dfs(grid,vis,i-1,j);
        }
        if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1]=='1')
        {
            dfs(grid,vis,i,j-1);
        }
}
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==false && grid[i][j]=='1')
                {
                    ans+=1;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};
