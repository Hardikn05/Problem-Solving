class Solution{
public:
	int power1(int mid,int n ,int m){
	    long long ans =1;
	    for(int i =1;i<=n;i++){
	        ans=ans*mid;
	        if(ans>m) return 2;
	    }
	    if(ans==m) return 0;
	    return 1;
	}
	
int NthRoot(int n, int m)
	{
	    // Code here.
	    int low=1,high=sqrt(m);
	    int mid;
	    if(n==1)
	    return m;
	    while(low<=high)
	    {
	        mid = low+(high-low)/2;
	         int val = power1(mid,n,m);
	        if(val==0)
	        {
	            return mid;
	        }
	        else if(val==1)
	        {
	            low = mid+1;
	        }
	        else{
	            high = mid - 1;
	        }
	    }
	    return -1;
	}  
};
