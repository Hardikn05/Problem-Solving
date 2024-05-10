class Solution {
public:
    int mod = 1e9+7;
    int memoization(int n,int k,int target,vector<vector<int>> &dp)
    {
        if(n==0 && target==0)
        return 1;
        else if(n==0 || target<=0)
        return 0;
        if(dp[n][target]!=-1)
        return dp[n][target];
        int ans = 0;
        for(int i=1;i<=k;i++)
        {
            ans=(ans%mod+(memoization(n-1,k,target-i,dp))%mod)%mod;
        }
        return dp[n][target]=ans;
    }
    int tabulation(int n, int k, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            for (int x = 1; x <= k && x <= j; x++) {
                dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - x] % mod) % mod;
            }
        }
    }

    return dp[n][target];
}
int spaceOptimized(int n, int k, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> currState(target + 1, 0);
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k; face++) {
                    if (j >= face)
                        currState[j] = (currState[j] + dp[j - face]) % mod;
                }
            }
            dp = currState;
        }

        return dp[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        // return memoization(n,k,target,dp);
        // return tabulation(n,k,target);
        return spaceOptimized(n,k,target);
    }
};
