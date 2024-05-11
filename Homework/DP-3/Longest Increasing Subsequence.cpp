class Solution {
public:
    //  Recursive Solution
    // int solve(vector<int>& nums,int idx,int prev_idx)
    // {
    //     if(idx==nums.size())
    //     return 0;

    //     int not_take = solve(nums,idx+1,prev_idx);
    //     int take = 0;
    //     if(prev_idx==-1 || nums[prev_idx]<nums[idx])
    //     {
    //         take=1+solve(nums,idx+1,idx);
    //     }
    //     return max(take,not_take);
    // }

    // Memoization Solution
    // int solve(vector<int>& nums,int idx,int prev_idx,vector<vector<int>> &dp)
    // {
    //     if(idx==nums.size())
    //     return 0;

    //     if(dp[idx+1][prev_idx+1]!=-1)
    //     return dp[idx+1][prev_idx+1];

    //     int not_take = solve(nums,idx+1,prev_idx,dp);
    //     int take = 0;
    //     if(prev_idx==-1 || nums[prev_idx]<nums[idx])
    //     {
    //         take=1+solve(nums,idx+1,idx,dp);
    //     }
    //     return dp[idx+1][prev_idx+1]=max(take,not_take);
    // }

    // Tabulation Method
    // int Tabulation(vector<int> nums)
    // {
    //     int n = nums.size();
    //     int dp[n];
    //     int ans = 0;
    //     dp[0]=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         int maxprevLis=0;
    //         for(int j=0;j<i;j++)
    //         {
    //             if(nums[i]>nums[j])
    //             {
    //                 maxprevLis=max(maxprevLis,dp[j]);
    //             }
    //         }
    //         dp[i]=maxprevLis+1;
    //         ans=max(dp[i],ans);
    //     }
    //     return ans;
    // }

    // Binary Search Method
    int BullShit(vector<int> nums,int x)
    {
        int i=0,j=nums.size()-1;
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            if(nums[mid]>=x)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
        return i;
    }
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            int n = dp.size();
            if(dp[n-1]<nums[i])
            dp.push_back(nums[i]);
            else
            {
                int j = BullShit(dp,nums[i]);
                dp[j]=nums[i];
            }
        }
        return dp.size();
        // return Tabulation(nums);
    }
};
