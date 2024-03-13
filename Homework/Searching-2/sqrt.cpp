class Solution {
public:
    int mySqrt(int x) {
        long long s=0,e=x;
        long long mid=s+(e-s)/2,ans;
        while(mid*mid!=x&&s<=e)
        {
            if(mid*mid>x)
            e=mid-1;
            else
        {
            ans=mid;
            s=mid+1;
        }
            mid=s+(e-s)/2;
        }
        if(mid*mid==x)
        return mid;
        else
        return ans;
    }
};