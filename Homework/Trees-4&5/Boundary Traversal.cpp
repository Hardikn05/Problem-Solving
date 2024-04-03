void LeftBoundary(TreeNode<int> *node, vector<int> &result)
{
    if (node == NULL) return;
    if (node->right || node->left) result.push_back(node->data);
    if(node->left) LeftBoundary(node->left, result);
    else LeftBoundary(node->right, result);
}

void RightBoundary(TreeNode<int> *node, vector<int> &result)
{
    if (node == NULL) return;
    if(node->right) RightBoundary(node->right, result);
    else RightBoundary(node->left,result);
    if (node->left || node->right) result.push_back(node->data);
}

void LeafNodes(TreeNode<int> *node, vector<int> &result)
{
    if (node == NULL) return;
    if (!node->left && !node->right) result.push_back(node->data);

    LeafNodes(node->left, result);
    LeafNodes(node->right, result);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    if (root == NULL) return {};
    vector<int> result;
    result.push_back(root->data);
    LeftBoundary(root->left, result);
    LeafNodes(root, result);
    RightBoundary(root->right, result);
    return result;
}
