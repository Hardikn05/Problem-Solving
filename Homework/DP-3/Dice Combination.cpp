#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int Memoization(int n,vector<int> &dp)
{
    if(n<=2)
    return n;

    if(dp[n]!=-1)
    return dp[n];

    int ans = 0;
    for(int i=1;i<=6;i++)
    {
        if(n-i>=0)
        {
            ans=(ans+Memoization(n-i,dp))%mod;
        }
    }
    if(n<=6)
    return dp[n]=(ans+1)%mod;
    else
    return dp[n]=ans%mod;
}
int Tabulation(int n)
{
    vector<int> dp(n+1,0);
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=6;j++)
        {
            if(i-j>=0)
            dp[i]=(dp[i]+dp[i-j])%mod;
            else
            break;
        }
        if(i<=6)
        dp[i]=(dp[i]+1)%mod;
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    // vector<int> dp(n+1,-1);
    cout<<Tabulation(n);

    return 0;
}
