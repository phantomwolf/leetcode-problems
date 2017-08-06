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
    int len = rotations.size();
    int d[len]; // d[i]: max height of the box stack with rotations[0..i]
    int s[len]; // s[i]: last choice

    d[0] = rotations[0].h;
    s[0] = -1;
    for (int i = 1; i < len; ++i) {
        d[i] = rotations[i].h;
        s[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (rotations[j].w > rotations[i].w &&
                rotations[j].d > rotations[i].d &&
                d[i] < d[j] + rotations[i].h) {
                d[i] = d[j] + rotations[i].h;
                s[i] = j;
            }
        }
    }

    // backtrace
    cout << endl << "box stacking: " << endl;
    int j = len - 1;
    while (j != -1) {
        cout << rotations[j].w << 'x' << rotations[j].d << 'x' << rotations[j].h << endl;
        j = s[j];
    }

    return d[len - 1];
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
    cout << "height: " << res << endl;
    return 0;
}
