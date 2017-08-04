#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


class Rotation
{
public:
    Rotation(int a, int b, int c): h(c)
    {
        if (a < b) {
            w = a;
            d = b;
        } else {
            w = b;
            d = a;
        }
    }

    bool operator<(const Rotation &other)
    {
        return this->w * this->d < other.w * other.d;
    }

    bool operator>(const Rotation &other)
    {
        return this->w * this->d > other.w * other.d;
    }

    int w;
    int d;
    int h;
};


int max_stack_height(const vector<vector<int>> &boxes)
{
    vector<Rotation> rotations;
    for (int i = 0; i < boxes.size(); ++i) {
        for (int j = 0; j < boxes[i].size(); ++j) {
            rotations.push_back(Rotation(boxes[i][j],
                                         boxes[i][(j + 1) % 3],
                                         boxes[i][(j + 2) % 3]));
        }
    }
    sort(rotations.begin(), rotations.end(), std::greater<Rotation&>());

    cout << "rotations: ";
    for (int i = 0; i < rotations.size(); ++i) {
        cout << rotations[i].w << 'x' << rotations[i].d << 'x' << rotations[i].h << ", ";
    }
    cout << endl;

    // Solve the LIS-like problem
}


int main(int argc, char *argv[])
{
    vector<vector<int>> boxes = {
        {4, 6, 7},
        {1, 2, 3},
        {4, 5, 6},
        {10, 12, 32},
    };

    int res = max_stack_height(boxes);
    return 0;
}
