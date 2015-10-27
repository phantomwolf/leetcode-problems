#include <iostream>
#include <vector>

using namespace std;

// bitmap/bit vector
// We can use char or int to build the bit vector

#define N   10000000

class MyBitmap8
{
public:
    MyBitmap8(int n) {
        this->max_num = n;
        bitmap = new char[1 + this->max_num/8];
    }

    ~MyBitmap8() {
        delete[] this->bitmap;
    }

    void insert(int i) {
        if (i > this->max_num)
            throw "Oh! Failed!";
        this->bitmap[i/8] |= (1<<(i & 7));
    }

    void insert(const vector<int> &nums) {
        vector<int>::const_iterator iter = nums.begin();
        while (iter != nums.end()) {
            this->insert(*iter);
            ++iter;
        }
    }

    void clear(int i) {
        this->bitmap[i/8] &= ~(1<<(i & 7));
    }

    bool test(int i) {
        return this->bitmap[i/8] & (1<<(i & 7));
    }

    void print() {
        for (int i=0; i < this->max_num; ++i) {
            if (this->bitmap[i/8] & (1<<(i & 7))) {
                cout << i << ", ";
            }
        }
        cout << endl;
    }

private:
    char *bitmap;
    int max_num;
};

class MyBitmap32
{
public:
    MyBitmap32(int n) {
        this->max_num = n;
        bitmap = new int32_t[1 + this->max_num/32];
    }

    ~MyBitmap32() {
        delete[] this->bitmap;
    }

    void insert(int i) {
        if (i > this->max_num)
            throw "Oh! Failed!";
        this->bitmap[i/32] |= (1<<(i & 31));
    }

    void insert(const vector<int> &nums) {
        vector<int>::const_iterator iter = nums.begin();
        while (iter != nums.end()) {
            this->insert(*iter);
            ++iter;
        }
    }

    void clear(int i) {
        this->bitmap[i/32] &= ~(1<<(i & 31));
    }

    bool test(int i) {
        return this->bitmap[i/32] & (1<<(i & 31));
    }

    void print() {
        for (int i=0; i < this->max_num; ++i) {
            if (this->bitmap[i/32] & (1<<(i & 31))) {
                cout << i << ", ";
            }
        }
        cout << endl;
    }

private:
    int32_t *bitmap;
    int max_num;
};


int main()
{
    vector<int> nums{3, 7, 5, 2, 4, 8, 4};
    MyBitmap32 bitmap32(10000000);
    bitmap32.insert(nums);
    bitmap32.print();
    return 0;
}
