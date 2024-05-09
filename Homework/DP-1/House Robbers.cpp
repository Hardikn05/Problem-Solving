class Solution {
public:

int Memoization(vector<int>& nums, int idx, vector<int>& dp) {
    if (idx >= nums.size())
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int take = nums[idx] + Memoization(nums, idx + 2, dp);
    int not_take = Memoization(nums, idx + 1, dp);

    return dp[idx] = max(take, not_take);
}
int Tabulation(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);
    if (n == 3) return max(nums[0] + nums[2], nums[1]);

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    dp[2] = max(nums[0] + nums[2], nums[1]);

    for (int i = 3; i < n; i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}
    // SpaceOptimization
    int rob(vector<int>& nums) {
        int n = nums.size();
        int temp1 = nums[0];

        if(n==1)
        return temp1;

        int temp2 = nums[1];
        if(n==2)
        return max(temp2,temp1);

        int temp3 = (nums[2]+temp1);
        if(n==3)
        return max(temp3,temp2);

        for(int i=3;i<n;i++)
        {
            int ans = nums[i]+max(temp1,temp2);
            temp1 = temp2;
            temp2 = temp3;
            temp3 = ans;
        }
        return max(temp3,temp2);
    }
};
