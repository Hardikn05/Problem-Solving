class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       if(root==NULL)
       return 0;
       
       return root->data - getLevelDiff(root->left)-getLevelDiff(root->right);
    }
};
