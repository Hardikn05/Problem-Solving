class Solution {
public:
    void dfs(vector<vector<int>> &vis,vector<vector<char>> &board,int i,int j)
    {
        if(vis[i][j]==1 || board[i][j]=='X')
        return;

        vis[i][j]=1;
        if(j+1<board[0].size())
        dfs(vis,board,i,j+1);
        if(j-1>=0)
        dfs(vis,board,i,j-1);
        if(i+1<board.size())
        dfs(vis,board,i+1,j);
        if(i-1>=0)
        dfs(vis,board,i-1,j);
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<int>> vis(board.size(),vector<int> (board[0].size(),0));
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<board.size();i++)
        {
            if(vis[i][0]==0 && board[i][0]=='O')
            dfs(vis,board,i,0);

            if(vis[i][n-1]==0 && board[i][n-1]=='O')
            dfs(vis,board,i,n-1);
        }
        for(int i=0;i<board[0].size();i++)
        {
            if(vis[0][i]==0 && board[0][i]=='O')
            dfs(vis,board,0,i);

            if(vis[m-1][i]==0 && board[m-1][i]=='O')
            dfs(vis,board,m-1,i);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && board[i][j]!='X')
                board[i][j]='X';
            }
        }
    }
};
