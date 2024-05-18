class Solution{
public:
    int Memoization(int arr[],int start,int end,vector<vector<int>> &dp)
    {
        if(start == end)
        return 0;
        
        if(dp[start][end]!=-1)
        return dp[start][end];
        int step = INT_MAX;
        for(int i=start;i<end;i++)
        {
            step = min(Memoization(arr,start,i,dp)+Memoization(arr,i+1,end,dp)+arr[start-1]*arr[i]*arr[end],step);
        }
        return dp[start][end]=step;
    }
    int Tabulation(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int step = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (step < dp[i][j]) {
                    dp[i][j] = step;
                }
            }
        }
    }
    return dp[1][n - 1];
}
    int matrixMultiplication(int N, int arr[])
    {
        
        vector<vector<int>>  dp(N,vector<int> (N,-1));
        return Memoization(arr,1,N-1,dp);
    }
};
