class Solution {
public:
    int solve(TreeNode* root,int &ans)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = solve(root->left,ans);
        int right = solve(root->right,ans);

        ans = max(ans,left+right);

        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int x=solve(root,ans);
        return ans;
    }
};
