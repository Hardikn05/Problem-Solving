#include<bits/stdc++.h>
using namespace std;

int Memoization(vector<int> &coins, int target, int idx, vector<vector<int>> &dp) {
    if (target == 0) return 0;  
    if (idx == coins.size()) return INT_MAX; 

    if (dp[idx][target] != -1) return dp[idx][target];

    int take = INT_MAX;
    if (target - coins[idx] >= 0) {
        int next = Memoization(coins, target - coins[idx], idx, dp);
        if (next != INT_MAX) take = 1 + next;  
    }

    int not_take = Memoization(coins, target, idx + 1, dp);

    return dp[idx][target] = min(take, not_take);
}
int Tabulation(vector<int> &coins, int target) {
    int n = coins.size();
    vector<int> dp(target + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : dp[target];
}
int main()
{
    int n;
    cin>>n;
    int money_target;
    cin>>money_target;

    vector<int> coins(n);
    for(int i=0;i<n;i++)
    cin>>coins[i];
    vector<vector<int>> dp(n,vector<int> (money_target+1,-1));
    int ans = Tabulation(coins,money_target);
    if(ans==INT_MAX)
    cout<<-1;
    else
    cout<<ans;
    return 0;
}
