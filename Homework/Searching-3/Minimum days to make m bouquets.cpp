class Solution{
public:
    bool check(int ball,vector<int>& nums, int maxops)
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>ball){
                if(nums[i]%ball==0)
                count+=(nums[i]/ball)-1;
                else
                count+=(nums[i]/ball);
            }
        }
        return count<=maxops;
    }
    int minimumSize(vector<int>& nums, int maxops) {
        int low = 1, high = INT_MIN;

        for(int i=0;i<nums.size();i++)
        high = max(nums[i],high);

        int mid,ans;

        while(low<=high)
        {
            cout<<low <<" "<<high<<endl;
            mid = low+(high-low)/2;
            if(check(mid,nums,maxops))
            {        
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
