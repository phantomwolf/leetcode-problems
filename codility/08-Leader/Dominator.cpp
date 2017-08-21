int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int majority;
    unsigned int count = 0;
    int index = -1;
    for (unsigned int i = 0; i < A.size(); ++i) {
        if (count == 0) {
            majority = A[i];
            count++;
            index = i;
        } else if (A[i] == majority) {
            count++;
        } else {
            count--;
        }
    }
    // Check if it is the majority element
    count = 0;
    for (unsigned int i = 0; i < A.size(); ++i) {
        if (A[i] == majority)
            count++;
    }
    if (A.size() - count < count)
        return index;
    return -1;
}
