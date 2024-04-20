#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* left, *right;
    long long count;
    TrieNode() {
        count = 0;
        left = NULL;
        right = NULL;
    }
};

TrieNode* root;

void insert(long long num) {
    TrieNode* current = root;
    for (int i = 63; i >= 0; i--) {
        long long bit = (num >> i) & 1LL;
        if (bit) {
            if (current->right == NULL)
                current->right = new TrieNode();
            current = current->right;
            current->count++;
        } else {
            if (current->left == NULL)
                current->left = new TrieNode();
            current = current->left;
            current->count++;
        }
    }
}

long long getCount(TrieNode* node) {
    return node == NULL ? 0 : node->count;
}

long long solve(long long num, long long target) {
    TrieNode* current = root;
    long long result = 0;
    for (int i = 63; i >= 0; i--) {
        long long numBit = (num >> i) & 1LL;
        long long targetBit = (target >> i) & 1LL;
        if (numBit) {
            if (targetBit) {
                result += getCount(current->right);
                if (current->left)
                    current = current->left;
                else
                    return result;
            } else {
                if (current->right)
                    current = current->right;
                else
                    return result;
            }
        } else {
            if (targetBit) {
                result += getCount(current->left);
                if (current->right)
                    current = current->right;
                else
                    return result;
            } else {
                if (current->left)
                    current = current->left;
                else
                    return result;
            }
        }
    }
    return result;
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        root = new TrieNode();
        int n, k;
        cin >> n >> k;
        long long result = 0;
        vector<long long> numbers(n);
        for (int i = 0; i < n; i++)
            cin >> numbers[i];
        insert(0);
        long long xorSum = 0;
        for (int i = 0; i < n; i++) {
            result += solve(xorSum ^ numbers[i], k);
            xorSum ^= numbers[i];
            insert(xorSum);
        }
        cout << result << endl;
    }
    return 0;
}
