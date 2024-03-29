
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(root==NULL) 
       return "";
       
       string s;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty())
       {
         TreeNode* temp = q.front();
         q.pop();
         if(temp==NULL)
         {
            s+="null,";
         }
         else
         {
            s+=to_string(temp->val)+",";
            q.push(temp->left);
            q.push(temp->right);
         }
       }
       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if( data.size()==0)
        return NULL;
      
      stringstream s(data);
      string str;
      getline(s,str,',');
      TreeNode* root = new TreeNode(stoi(str));
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        TreeNode* curr_node = q.front();
        q.pop();
        getline(s,str,',');
        if(str=="null")
        {
            curr_node->left=NULL;
        }
        else
        {
            TreeNode* left = new TreeNode(stoi(str));
            q.push(left);
            curr_node->left=left;
        }
        getline(s,str,',');
        if(str=="null")
        {
            curr_node->right=NULL;
        }
        else
        {
            TreeNode* left = new TreeNode(stoi(str));
            q.push(left);
            curr_node->right=left;
        }
      }
      return root;
    }
};
