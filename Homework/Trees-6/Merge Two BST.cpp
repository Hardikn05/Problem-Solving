Solution {
public:

    void inorder(Node* root, std::vector<int>& inord) {
        if (root == nullptr) 
            return;
        
        inorder(root->left, inord);
        inord.push_back(root->data);
        inorder(root->right, inord);
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> inorder1;
        vector<int> inorder2;
        vector<int> mergedArray;

        inorder(root1, inorder1);
        inorder(root2, inorder2);

        int i = 0, j = 0;
        while (i < inorder1.size() && j < inorder2.size()) {
            if (inorder1[i] < inorder2[j]) {
                mergedArray.push_back(inorder1[i++]);
            } else {
                mergedArray.push_back(inorder2[j++]);
            }
        }

        while (i < inorder1.size()) {
            mergedArray.push_back(inorder1[i++]);
        }
        while (j < inorder2.size()) {
            mergedArray.push_back(inorder2[j++]);
        }

        return mergedArray;
    }
};
