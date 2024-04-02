class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    void inorder(Node* root,vector<int> &save)
    {
        if(root==NULL)
        return;
        
        inorder(root->left,save);
        save.push_back(root->data);
        inorder(root->right,save);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
       vector<int> ans,save1,save2;
       inorder(root1,save1);
       inorder(root2,save2);
       
       int i=0,j=0;
       while(i<save1.size() && j<save2.size()){
           if(save1[i]==save2[j])
           {
               ans.push_back(save1[i]);
               i++,j++;
           }
           else if(save1[i]<save2[j])
           {
               i++;
           }
           else
           {
               j++;
           }
       }
       return ans;
    }
};
