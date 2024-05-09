class Solution
{
public:
    int mod = 1000000007;
    long long memoization(int n,vector<long long> &dp)
    {
        if(n==1||n==2)
        return n;
        if(dp[n]!=-1)
        return dp[n];
    
        return dp[n]=(memoization(n-1,dp)%mod+(n-1)*memoization(n-2,dp)%mod)%mod;
    }
    long long Tabulation(int n)
    {
        vector<long long> dp(n+1);
        dp[1]=1;
        if(n==1)
        return 1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]+(i-1)*dp[i-2]%mod)%mod;
        }
        return dp[n];
    }
    long long SpaceOptimization(int n)
    {
        if(n<=2)
        return n;
        
        long long temp1 = 1,temp2 = 2;
        for(int i=3;i<=n;i++)
        {
            long long current = (temp2+(i-1)*temp1%mod)%mod;
            temp1 = temp2;
            temp2 = current;
        }
        return temp2;
    }
    int countFriendsPairings(int n) {
        return SpaceOptimization(n);
    }
};   
