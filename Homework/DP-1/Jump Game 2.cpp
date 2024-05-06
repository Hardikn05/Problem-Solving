class Solution {
public:
    int spaceOptimization(vector<int>& nums) {
        int ri=0,rs=0,step=0;
        if(nums.size()==1)
        return step;
        for(int i=0;i<nums.size();i++)
        {
            ri=max(ri,nums[i]+i);
            if(i==rs)
            {
                step++;
                rs=ri;
            }
            if(rs>=nums.size()-1)
            return step;

        }
        return step;
    }
    int Tabulation(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);

    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        int ans = INT_MAX;
        for (int j = 1; j <= nums[i] && i + j < n; j++) {
            ans = min(ans, dp[i + j]);
        }
        dp[i] = (ans == INT_MAX) ? INT_MAX : ans + 1;
    }
    return dp[0];
}
    int Memoization(vector<int> &nums,int i,vector<int> &dp)
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
            ans = min(ans,Memoization(nums,i+j,dp));
        }
        return dp[i]=(ans==INT_MAX)?INT_MAX:ans+1;
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1)
        return 0;
        vector<int> dp(nums.size(),-1);
        // return solve(nums,0,dp);
        return spaceOptimization(nums);
    }
};
