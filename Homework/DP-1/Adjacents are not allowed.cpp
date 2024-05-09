class Solution{
public:
    int Memoization(vector<vector<int>> &nums,int idx,vector<int> &dp)
    {
        if(idx>=nums[0].size())
        return 0;
        
        if(dp[idx]!=-1)
        return dp[idx];
        
        int not_take = solve(nums,idx+1,dp);
        int take = solve(nums,idx+2,dp)+max(nums[0][idx],nums[1][idx]);

        return dp[idx]=max(take,not_take);
    }
    int Tabulation(vector<vector<int>> &nums) {
    int n = nums[0].size();
    vector<int> dp(n + 2, 0);
    
    for (int idx = n - 1; idx >= 0; idx--) {
        int not_take = dp[idx + 1];
        int take = dp[idx + 2] + max(nums[0][idx], nums[1][idx]);
        
        dp[idx] = max(take, not_take);
    }
    
    return dp[0];
}
    int SpaceOptimization(int N, vector<vector<int>> mat)
    {
        int temp1 = max(mat[0][0],mat[1][0]);
        if(N==1)
        return temp1;
        
        int temp2 = max(mat[1][1],mat[0][1]);
        if(N==2)
        return max(temp1,temp2);
        
        int temp3 = temp1+max(mat[0][2],mat[1][2]);
        if(N==3)
        return max(temp2,temp3);
        
        for(int i=3;i<N;i++)
        {
            int ans = max(temp1,temp2)+max(mat[0][i],mat[1][i]);
            temp1 = temp2;
            temp2 = temp3;
            temp3 = ans;
        }
        return max(temp2,temp3);
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<int> dp(N,-1);
        
        return solve(mat,0,dp);
    }
};
