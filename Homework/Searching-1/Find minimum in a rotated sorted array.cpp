class Solution {
public:
    int findMin(vector<int>& nums) {
        int lb=0,ub=nums.size()-1;
        int mid=lb+(ub-lb)/2;
        
        while(lb<ub)
        {
            if(nums[lb]<nums[ub])
            break;
            if(nums[mid]>=nums[lb])
            lb=mid+1; 
            else
            ub=mid;
            mid=lb+(ub-lb)/2;
        }
        return nums[lb];
    }
};