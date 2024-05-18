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
    int matrixMultiplication(int N, int arr[])
    {
        
        vector<vector<int>>  dp(N,vector<int> (N,-1));
        return Memoization(arr,1,N-1,dp);
    }
};
