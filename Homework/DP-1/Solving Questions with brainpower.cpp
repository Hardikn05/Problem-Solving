class Solution {
public:
    long long Memoization(vector<vector<int>> &questions,int idx,vector<long long> &dp)
    {
        if(idx>=questions.size())
        return 0;

        if(dp[idx]!=-1)
        return dp[idx];

        long long take = Memoization(questions,idx+questions[idx][1]+1,dp)+questions[idx][0];
        long long not_take = Memoization(questions,idx+1,dp);

        return dp[idx]=max(take,not_take);
    }
    // Tabulation
    long long mostPoints(vector<vector<int>>& questions) {
       int n=questions.size();
        int mx=INT_MIN;
        for(auto x:questions)
        {
            mx=max(mx,x[1]);
        }
        vector<long long> dp(n+mx+1,0);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=max(questions[i][0]+dp[i+questions[i][1]+1],dp[i+1]);
        }
        return dp[0];
    }
};
