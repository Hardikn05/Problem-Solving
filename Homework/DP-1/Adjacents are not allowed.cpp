class Solution{
public:
    int solve(vector<vector<int>> &nums,int idx,vector<int> &dp)
    {
        if(idx>=nums[0].size())
        return 0;
        
        if(dp[idx]!=-1)
        return dp[idx];
        
        int not_take = solve(nums,idx+1,dp);
        int take = solve(nums,idx+2,dp)+max(nums[0][idx],nums[1][idx]);

        return dp[idx]=max(take,not_take);
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<int> dp(N,-1);
        
        return solve(mat,0,dp);
    }
};
