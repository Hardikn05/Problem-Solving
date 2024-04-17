class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        queue<pair<pair<int,int>,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(make_pair(i,j),0));
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        int te=0;
        int r[4]={-1,0,1,0};
        int c[4]={0,-1,0,1};

        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            te=max(te,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+r[i];
                int ncol=col+c[i];

                if(nrow<m && nrow>=0 && ncol>=0 && ncol<n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)
                {
                    q.push(make_pair(make_pair(nrow,ncol),t+1));
                    vis[nrow][ncol]=2;
                    count--;
                }
            }
        }
        if(count>0)
        return -1;

        return te;
    }
};
