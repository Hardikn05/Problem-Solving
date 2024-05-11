class Solution {
public:
    int solve(vector<int> &coins,int amount,int idx,vector<vector<int>> &dp)
    {
        if(idx<0)
        {
            return 1000000;
        }
        if(amount==0)
        {
            return 0;
        }
        else if(amount<0)
        {
            return 1000000;
        }

        if(dp[amount][idx]!=-1)
        return dp[amount][idx];
        int leave=1+solve(coins,amount-coins[idx],idx-1,dp);
        int not_leave=1+solve(coins,amount-coins[idx],idx,dp);
        int lv=solve(coins,amount,idx-1,dp);
        
        
        return dp[amount][idx]=min({leave,not_leave,lv});
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(amount+1,vector<int> (coins.size(),-1));
        int temp=solve(coins,amount,coins.size()-1,dp);

        if(temp>100000)
        return -1;
        else
        return temp;
    }
};
