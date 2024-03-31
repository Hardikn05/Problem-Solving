class Solution {
public:
    TreeNode* buildTree(vector<int> &nums,int low,int high)
    {
        if(low<=high){
            int mid = low + (high-low)/2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = buildTree(nums,low,mid-1);
            node->right = buildTree(nums,mid+1,high);
            return node;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        return buildTree(nums,low,high);
    }
};
