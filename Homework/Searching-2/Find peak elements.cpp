class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int mid=0;
        while(i<=j)
        {
         mid=i+(j-i)/2;
         if(mid-1>=0 && mid+1<nums.size() && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
         {
             return mid;
         }
         else if(mid+1<nums.size() && nums[mid+1]>nums[mid]){
             i=mid+1;
         }
         else
         {
             j=mid-1;
         }
        }
         return mid;
    }
};