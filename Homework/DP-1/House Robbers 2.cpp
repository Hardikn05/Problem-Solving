class Solution {
public:
    int Memoization(vector<int>& nums,int curr,int n,vector<int>& dp){
        if(curr>=n) return 0;
        if(dp[curr]!=-1) return dp[curr];
        int inc = nums[curr]+Memoization(nums,curr+2,n,dp);
        int exc = Memoization(nums,curr+1,n,dp);
        return dp[curr]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        vector<int> dp(n,-1);
        int op1 = Memoization(nums,0,n-1,dp);
        fill(dp.begin(),dp.end(),-1);
        int op2 = Memoization(nums,1,n,dp);
        return max(op1,op2);
    }
    // Tabulation
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        for(int i=1;i<n-1;i++){
            dp[i] = max(dp[i-1],nums[i]+(i-2>=0?dp[i-2]:0));
        }
        int ans = dp[n-2];
        fill(dp.begin(),dp.end(),-1);
        dp[1] = nums[1];
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],nums[i]+(i-2>=1?dp[i-2]:0));
        }
        ans = max(ans,dp[n-1]);
        return ans;
    }
};
