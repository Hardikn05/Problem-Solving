class Solution {
public:
    int spaceOptimization(int n) {

        if(n==1)
        return 1;
        else if(n==2)
        return 2;

        int temp1 = 1;
        int temp2 = 2;

        int temp3;
        for(int i=3;i<=n;i++)
        {
            temp3 = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp3;
        }

        return temp3;
    }
    int Memoization(int n,vector<int> &dp)
    {
        if(n==1 || n==2)
        return n;

        if(dp[n]!=-1)
        return dp[n];

        int onejump = Memoization(n-1,dp);
        int twojump = Memoization(n-2,dp);

        return dp[n]=onejump+twojump;
    }
    int Tabulation(int n)
    {
        vector<int> dp(n+1);
        dp[1]=1;
        if(n==1)
        return 1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return Memoization(n,dp);
        return Tabulation(n);
    }
};
