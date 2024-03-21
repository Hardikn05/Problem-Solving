int upperbound(vector<int> A,int n,int mid)
{
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high)
    {
        int mid1 = (low + high)>>1;
       if(A[mid1]>mid) {
           ans = mid1;
           high = mid1-1;
       }
       else
        low = mid1+1;
    }
    return ans;
}
int count(vector<vector<int>> &A,int m,int n,int mid)
{
    int ginti = 0;
    for(int i=0;i<m;i++)
    {
        ginti+= upperbound(A[i],n,mid);
    }
    return ginti;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = INT_MAX,high = INT_MIN;
    int m=A.size(),n=A[0].size();
    for(int i=0;i<m;i++)
    {
        low = min(low,A[i][0]);
        high = max(high,A[i][n-1]);
    }
    
    int req = (n*m)/2;
    while(low<=high)
    {
        int mid = (low+high)>>1;
        int small = count(A,m,n,mid);
        if(small <= req) low = mid+1;
        else
        high = mid - 1;
    }
    return low;
}
