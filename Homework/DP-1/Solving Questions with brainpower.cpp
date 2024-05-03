class Solution {
public:
    long long solve(vector<vector<int>> &questions,int idx,vector<long long> &dp)
    {
        if(idx>=questions.size())
        return 0;

        if(dp[idx]!=-1)
        return dp[idx];

        long long take = solve(questions,idx+questions[idx][1]+1,dp)+questions[idx][0];
        long long not_take = solve(questions,idx+1,dp);

        return dp[idx]=max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<long long> dp(questions.size(),-1);
        return solve(questions,0,dp);
    }
};
