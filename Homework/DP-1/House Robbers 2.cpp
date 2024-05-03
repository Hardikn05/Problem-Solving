class Solution {
public:
    int solve(vector<int> nums,int n,vector<int> &dp)
    {
        if(n<0)
        return 0;

        if(n==0)
        return nums[0];

        if(dp[n]!=-1)
        return dp[n];

        int include=solve(nums,n-2,dp)+nums[n];
        int exclude=solve(nums,n-1,dp);

        dp[n]=max(include,exclude);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int> first,second,dp1(nums.size()+1,-1),dp2(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
            second.push_back(nums[i]);
            if(i!=nums.size()-1)
            first.push_back(nums[i]);
        }

        return max(solve(first,first.size()-1,dp1),solve(second,second.size()-1,dp2));
    }
};
