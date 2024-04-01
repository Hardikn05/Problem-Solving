struct DSA {
    bool isBST;
    int minVal, maxVal, size;
    DSA() {
        isBST = true;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        size = 0;
    }
};

DSA solve(Node* root) {
    if (!root) return DSA();
    DSA left = solve(root->left);
    DSA right = solve(root->right);
    if (left.isBST && right.isBST && left.maxVal < root->data && root->data < right.minVal) {
        DSA result;
        result.isBST = true;
        result.size = 1 + left.size + right.size;
        result.minVal = min(root->data, left.minVal);
        result.maxVal = max(root->data, right.maxVal);
        return result;
    } else {
        DSA result;
        result.isBST = false;
        result.minVal = INT_MIN;
        result.maxVal = INT_MAX;
        result.size = max(left.size, right.size);
        return result;
    }
}

class Solution {
public:
    int largestBst(Node *root) {
        return solve(root).size;
    }
};
