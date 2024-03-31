void solve(Node* root,int input,int &ans)
{
    if(root==NULL) return;
    if(root->data<input)
    {
        solve(root->right,input,ans);
    }
    else
    {
        if(root->data==input)
        {
            ans = input;
            return;
        }
        else
        {
            ans = root->data;
            solve(root->left,input,ans);
        }
    }
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans = -1;
    solve(root,input,ans);
    return ans;
    // Your code here
}
