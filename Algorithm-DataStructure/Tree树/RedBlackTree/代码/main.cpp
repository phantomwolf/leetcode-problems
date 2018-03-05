#include "rbtree.h"
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
    RBTree rbtree;
    vector<int> nums{10, 20, 30, 15};
    for (int i = 0; i < nums.size(); ++i) {
        cout << "Inserting " << nums[i] << "..." << endl;
        rbtree.insert(nums[i]);
        rbtree.show();
    }


    return 0;
}
