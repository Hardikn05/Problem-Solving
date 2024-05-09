class Solution {
public:
    int Memoization2(vector<int> &square,int idx,int n,vector<vector<int>> &dp)
    {
        if(n==1||n==0)
        return n;

        if(idx>=square.size() || n<0)
        return 1e5;

        if(dp[idx][n]!=-1)
        return dp[idx][n];

        int pick = Memoization2(square,idx,n-square[idx],dp)+1;
        int not_pick = Memoization2(square,idx+1,n,dp);

        return dp[idx][n]=min(pick,not_pick);
    }
    int Tabulation2(vector<int> &square, int n) {
    vector<vector<int>> dp(square.size(), vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < square.size(); ++i)
        dp[i][0] = 0;

    for (int i = 0; i < square.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 0)
                dp[i][j] = (j >= square[i]) ? 1 + dp[i][j - square[i]] : INT_MAX; 
            else {
                int pick = (j >= square[i]) ? 1 + dp[i][j - square[i]] : INT_MAX;
                int not_pick = dp[i - 1][j]; 
                dp[i][j] = min(pick, not_pick);
            }
        }
    }

    return dp[square.size() - 1][n];
}


    int Memoization(int n,vector<int> &dp)
    {
        if(n==0)
        return 0;

        if(dp[n]!=-1)
        return dp[n];

        int ans=n;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,Memoization(n-i*i,dp)+1);
        }
        return dp[n]= ans;;
    }
    int Tabulation(int n) {
    if (n == 0)
        return 0;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}

    int SpaceOptimization(int n) {
    if (n == 0)
        return 0;

    int dp_curr = 0;
    int dp_prev = 0; 

    for (int i = 1; i <= n; ++i) {
        dp_curr = i;

        for (int j = 1; j * j <= i; ++j) {
            dp_curr = min(dp_curr, dp_prev + 1);
        }

        dp_prev = dp_curr;
    }

    return dp_curr;
}

    int numSquares(int n) {
        vector<int> square;
        for(int i=1;i*i<=n;i++)
        {
            square.push_back(i*i);
        }
        vector<vector<int>> dp(square.size(),vector<int> (n+1,-1));
        return SpaceOptimization(n);
    }
};
