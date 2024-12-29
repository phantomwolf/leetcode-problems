#include <cstdint>
#include <string>

using namespace std;

typedef struct TrieNode TrieNode;

struct TrieNode {
    TrieNode() {
        this->child[0] = nullptr;
        this->child[1] = nullptr;
        this->count = 0;
    }

    ~TrieNode() {
        for (int i = 0; i < 2; ++i) {
            if (this->child[i] != nullptr)
                delete this->child[i];
        }
    }

    inline bool is_leaf() {
        if (this->child[0] || this->child[1])
            return false;
        return true;
    }

    TrieNode *child[2];
    size_t count;
};


class Trie {
public:
    Trie() {
        this->root = new TrieNode();
    }

    ~Trie() {
        delete this->root;
    }

    void insert(uint32_t num) {
        uint32_t probe = 0x80000000;
        TrieNode *node = this->root;
        while (probe != 0) {
            if (num & probe) {
                // current bit is 1
                if (node->child[1] == nullptr)
                    node->child[1] = new TrieNode();
                node = node->child[1];
            } else {
                // current bit is 0
                if (node->child[0] == nullptr)
                    node->child[0] = new TrieNode();
                node = node->child[0];
            }
            probe >>= 1;
        }
        ++node->count;
    }

    // Return the maximum XOR result we can get
    // by doing XOR operator between q and any number stored inside Trie
    uint32_t query(uint32_t q) {
        uint32_t max_xor = 0;
        uint32_t probe = 0x80000000;

        TrieNode *node = this->root;
        while (probe != 0) {
            if (q & probe) {
                // current bit of q is 1
                if (node->child[0] != nullptr) {
                    node = node->child[0];
                    max_xor |= probe;
                } else {
                    node = node->child[1];
                }
            } else {
                // current bit of q is 0
                if (node->child[1] != nullptr) {
                    node = node->child[1];
                    max_xor |= probe;
                } else {
                    node = node->child[0];
                }
            }
            probe >>= 1;
        }
        return max_xor;
    }

    // Return how many numbers inside trie can generate
    // a smaller value than k if we do XOR between it and q.
    uint32_t count(uint32_t q, uint32_t k)
    {
        uint32_t res = 0;
        uint32_t probe = 0x80000000;
        TrieNode *node = this->root;
        while (node != nullptr && probe != 0) {
            if (k & probe) {
                // current bit of k is 1
                if (q & probe) {
                    // current bit of q is 1
                    if (node->child[1] != nullptr)
                        res += this->count_leaves(node->child[1]);
                    node = node->child[0];
                } else {
                    // current bit of q is 0
                    if (node->child[0] != nullptr)
                        res += this->count_leaves(node->child[0]);
                    node = node->child[1];
                }
            } else {
                // current bit of k is 0
                if (q & probe) {
                    // current bit of q is 1
                    node = node->child[1];
                } else {
                    // current bit of q is 0
                    node = node->child[0];
                }
            }
            probe >>= 1;
        }
        return res;
    }

    // Return how many leaf nodes the subtree has
    uint32_t count_leaves(TrieNode *node)
    {
        if (node->is_leaf())
            return node->count;
        int res = 0;
        if (node->child[0])
            res += this->count_leaves(node->child[0]);
        if (node->child[1])
            res += this->count_leaves(node->child[1]);
        return res;
    }

    void print(TrieNode *node = nullptr, string tmp = "") {
        if (node == nullptr)
            node = this->root;
        if (node->child[0]) {
            this->print(node->child[0], tmp + '0');
        }
        if (node->child[1]) {
            this->print(node->child[1], tmp + '1');
        }
        if (node->child[0] == nullptr && node->child[1] == nullptr) {
            cout << tmp << endl;
        }
    }


    TrieNode *root;
};
