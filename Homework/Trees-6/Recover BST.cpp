class Solution {
public:
    TreeNode* node1,*node2,*prev=NULL;
    bool found;
    void solve(TreeNode* root)
    {
        if(!root)
        return;
        solve(root->left);
        if(prev!=NULL)
        {
        
            if(prev->val>root->val && !found)
            {
                found=true;
                node1=prev;
                node2=root;
            }
            else if(prev->val>root->val && found)
                node2=root;
        }
        prev=root;
        solve(root->right);
    }

    void recoverTree(TreeNode* root) {
        found = false;
        solve(root);
        int val = node1->val;
        node1->val = node2->val;
        node2->val = val;
    }
};
