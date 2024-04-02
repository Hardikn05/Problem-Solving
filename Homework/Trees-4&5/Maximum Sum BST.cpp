class Solution {
public:
    class DSA{
        public:
        bool isbst;
        int mini,maxi,sum;
        DSA()
        {
            isbst = true;
            mini = INT_MAX;
            maxi = INT_MIN;
            sum = 0;
        }
    };
    DSA solve(TreeNode* root,int &final_ans)
    {
        if(root==NULL) return DSA();

        DSA left = solve(root->left,final_ans);
        DSA right = solve(root->right,final_ans);
        if(left.isbst && right.isbst && left.maxi<root->val && right.mini>root->val)
        {
            DSA ans;
            ans.mini = min(left.mini,root->val);
            ans.maxi = max(right.maxi,root->val);

            ans.sum = (left.sum)+(right.sum)+root->val;
            final_ans = max({ans.sum,final_ans});
            return ans;
        }
        else
        {
            DSA ans;
            ans.isbst = false;
            ans.mini = INT_MIN;
            ans.maxi = INT_MAX;
            ans.sum = max({left.sum,right.sum,0});
            final_ans = max(ans.sum,final_ans);
            return ans;
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
