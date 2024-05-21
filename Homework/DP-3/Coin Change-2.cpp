class Solution {
public:
    int Memoization(vector<int> &coins,int amount,int index,vector<vector<int>> &dp)
    {
        if(amount == 0)
        return 1;

        if(index==coins.size() || amount<0)
        return 0;

        if(dp[amount][index]!=-1)
        return dp[amount][index];
        int not_take = Memoization(coins,amount,index+1,dp);
        amount-=coins[index];
        int take = Memoization(coins,amount,index,dp);
        amount+=coins[index];
        return dp[amount][index]=take+not_take;
    }
int Tabulation(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));
    for(int j = 0; j <= n; j++) {
        dp[0][j] = 1;
    }
    for(int i = 1; i <= amount; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if(i >= coins[j - 1]) {
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
    }
    return dp[amount][n];
}

    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(amount+1,vector<int> (coins.size(),-1));
        return Tabulation(amount,coins);
    }
};
