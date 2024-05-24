class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> length(n,1);
        int max_LIS=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        length[i]=length[j];
                        max_LIS=max(max_LIS,dp[i]);
                    }
                    else if(dp[i]==dp[j]+1)
                        length[i]+=length[j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            if(dp[i]==max_LIS)
                ans+=length[i];
        return ans;
    }
};
