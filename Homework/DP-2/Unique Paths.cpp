class Solution {
public:

    int Memoization(int m,int n,vector<vector<int>> &dp)
    {
    if( m == 1 && n == 1)
    {
        dp[m][n]=1;
        return dp[m][n];
    }
    else if(m<1 || n<1)
    {
        dp[m][n]=0;
        return dp[m][n];
    }

    if(dp[m][n]!=-1)
    return dp[m][n];

    int left = Memoization(m-1,n,dp);
    int right = Memoization(m,n-1,dp);

    dp[m][n] = left+right;
    return dp[m][n];
    }
    int uniquePaths(int m, int n)
         {
         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
         return Memoization(m,n,dp);
    }
};
