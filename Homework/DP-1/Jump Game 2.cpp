class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int> &dp)
    {
        if(i>=nums.size()-1)
        {
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int ans = INT_MAX;
        for(int j=1;j<=nums[i];j++)
        {
            ans = min(ans,solve(nums,i+j,dp));
        }
        return dp[i]=(ans==INT_MAX)?INT_MAX:ans+1;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};
