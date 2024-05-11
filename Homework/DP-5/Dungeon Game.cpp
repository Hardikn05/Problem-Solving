class Solution {
public:
    int solve(vector<vector<int>> &dungeon,int i,int j,vector<vector<int>> &dp)
    {
        int m = dungeon.size()-1;
        int n = dungeon[0].size()-1;
        if(i==m && j==n)
        {
            if(dungeon[i][j]>=0)
                return 1;
            else
                return abs(dungeon[i][j])+1;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];

        int right = 1e8;
        if(j+1<=n)
        right=solve(dungeon,i,j+1,dp);
        int bottom = 1e8;
        if(i+1<=m)
        bottom=solve(dungeon,i+1,j,dp);

        if(dungeon[i][j]<=0)
        {
            dp[i][j]=abs(dungeon[i][j])+min(right,bottom);
        }
        else
        {
            dp[i][j]=max(1,min(right,bottom)-dungeon[i][j]);
        }
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(),vector<int> (dungeon[0].size(),-1));
        return solve(dungeon,0,0,dp);
    }
};
