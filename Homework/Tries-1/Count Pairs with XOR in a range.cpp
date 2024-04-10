class TrieNode {
public:
    TrieNode* children[2];
    int count;
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        count = 0;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* current = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (current->children[bit] == nullptr) {
                current->children[bit] = new TrieNode();
            }
            current = current->children[bit];
            current->count++;
        }
    }

    int countXorPairs(int num, int high) {
        TrieNode* current = root;
        int countPairs = 0;
        for (int i = 31; i >= 0 && current != nullptr; i--) {
            int bitNum = (num >> i) & 1;
            int bitHigh = (high >> i) & 1;
            if (bitHigh == 1) {
                if (current->children[bitNum] != nullptr) {
                    countPairs += current->children[bitNum]->count;
                }
                current = current->children[1 - bitNum];
            } else {
                current = current->children[bitNum];
            }
        }
        return countPairs;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie trie;
        int countPairs = 0;
        for (int num : nums) {
            countPairs += trie.countXorPairs(num, high + 1) - trie.countXorPairs(num, low);
            trie.insert(num);
            cout<<countPairs<<" ";
        }
        return countPairs;
    }
};
