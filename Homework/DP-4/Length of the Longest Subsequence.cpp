class Solution {
public:
    int Memoization(vector<int> &nums,int target,int idx,vector<vector<int>> &dp)
    {
        if(target==0)
        return 0;
        else if(target<0 || idx==nums.size())
        return INT_MIN;

        if(dp[idx][target]!=-1)
        return dp[idx][target];

        int take = 1+Memoization(nums,target-nums[idx],idx+1,dp);
        int not_take = Memoization(nums,target,idx+1,dp);
        
        return dp[idx][target]=max(take,not_take);
    }
    int Tabulation(vector<int> &nums, int target) {
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));


    for(int i = 0; i < nums.size(); i++) {
        dp[i][0] = 0;
    }

    for(int j = 1; j <= target; j++) {
        if(j == nums[0]) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = -1;
        }
    }

    for(int i = 1; i < nums.size(); i++) {
        for(int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            
            if(j - nums[i] >= 0 && dp[i - 1][j - nums[i]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - nums[i]] + 1);
            }
        }
    }

    return dp[nums.size() - 1][target];
}

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        vector<vector<int>> dp(nums.size(),vector<int> (target+1,-1));
        int ans = Tabulation(nums,target);
        return ans<=0?-1:ans;
    }
};
