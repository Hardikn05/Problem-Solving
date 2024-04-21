class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	      int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<vector<int>> ans(m,vector<int> (n,INT_MAX));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    ans[i][j]=0;
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<int> dx = {0,0,1,-1} , dy = {1,-1,0,0};
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dis =q.front().second;
            ans[i][j] = dis;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int x = i+dx[k];
                int y = j+dy[k];

                if(x<m && y<n && x>=0 && y>=0 && !vis[x][y] && mat[x][y]==0)
                {
                    
                    q.push({{x,y},dis+1});
                    vis[x][y]=1;
                }
            }
        }
        return ans;
	}
};
