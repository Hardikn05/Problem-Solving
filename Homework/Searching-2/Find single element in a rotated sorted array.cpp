class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=1,high=nums.size()-2;
        int mid;
        // array size == 1
        if(nums.size()==1)
        return nums[0];
//       first number is ans
        if(nums[0]!=nums[1])
        return nums[0];
//       last number is ans
        if(nums[nums.size()-1]!=nums[nums.size()-2])
        nums[nums.size()-1];

        while(low<=high)
        {
            mid = low+(high-low )/2;
            bool check = false;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])
            return nums[mid];

            else if(nums[mid]==nums[mid-1])
            {
            mid = mid-1;
            check = true;
            }

            if(mid%2==0)
            {
                low = mid+1;
                if(check)
                low++;
            }
            else{
                high = mid-1;
            }
        }
        return nums[low];
    }
};