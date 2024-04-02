class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
         if(root==NULL)
         return 0;

         int left = rangeSumBST(root->left,low,high);
         int right = rangeSumBST(root->right,low,high);

         int ans = 0;
         if(root->val>=low && root->val<=high)
         {
            ans+=root->val;
         }

         return ans+left+right;
    }
};
