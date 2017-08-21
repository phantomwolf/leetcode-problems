#include <iostream>
#include <climits>


using namespace std;


const int T = 5;        // degree of BTree


class BNode
{
    int     *keys;      // keys
    BNode   **child;    // child nodes
    int     n;          // current number of keys
    bool    leaf;       // true if it's a leaf node
public:
    // t: degree
    BNode(bool leaf)
    {
        this->keys      = new int[2 * T - 1];
        this->child     = new BNode*[2 * T];
        this->n         = 0;
        this->leaf      = leaf;
    }

    ~BNode()
    {
        delete[] this->keys;
        delete[] this->child;
    }

    int insert(int key)
    {
        int i = n - 1;
        while (i >= 0 && key < this->keys[i]) {
            this->keys[i + 1] = this->keys[i - 1];
            --i;
        }
        this->keys[i + 1] = key;
        ++this->n;
    }

    friend class BTree;

};

class BTree
{
};


int main(int argc, char *argv[])
{
    return 0;
}
