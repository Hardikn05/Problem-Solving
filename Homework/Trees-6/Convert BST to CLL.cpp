class  Solution {
private:
    Node *tail = nullptr;
    Node *previous = nullptr;
    Node *head = nullptr;

    void convertToCircularDLL(Node* root) {
        if (!root)
            return;

        convertToCircularDLL(root->left);

        root->left = previous;

        if (previous)
            previous->right = root;
        else
            head = root;

        previous = root;

        tail = root;

        convertToCircularDLL(root->right);
    }

public:
    Node *bTreeToCList(Node *root) {
        if (!root)
            return nullptr;

        convertToCircularDLL(root);
        
        head->left = tail;
        tail->right = head;

        return head;
    }
};
