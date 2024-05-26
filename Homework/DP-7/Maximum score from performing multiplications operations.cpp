class Solution {
public:
        int solve(vector<int> &nums,int low,vector<int> &mul,int idx,vector<vector<int>> &dp)
        {
            if(idx==mul.size())
            return 0;

            if(dp[low][idx]!=-1)
            return dp[low][idx];

            int high = nums.size()-1-(idx-low);

            int first = solve(nums,low+1,mul,idx+1,dp) + nums[low]*mul[idx];
            int last = solve(nums,low,mul,idx+1,dp) + nums[high]*mul[idx];

            return dp[low][idx]=max(first,last);
        }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {

        vector<vector<int>> dp(nums.size(),vector<int> (multipliers.size(),-1));
        return solve(nums,0,multipliers,0,dp);
    }
};
