class Solution {
public:
    TreeNode* solve(int mini,int maxi,vector<int>& preorder,int &idx)
    {
         if(idx >= preorder.size())
         return NULL;

         if(preorder[idx]>maxi || preorder[idx]<mini)
         return NULL;

         TreeNode* root = new TreeNode(preorder[idx++]);

         root->left = solve(mini,root->val,preorder,idx);
         root->right = solve(root->val,maxi,preorder,idx);

         return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;

        int idx = 0;
        return solve(mini,maxi,preorder,idx);
    }
};
