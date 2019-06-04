# 3. Strings, Vectors, and Arrays
## 3.2 STL string
### Range for
If we want to do something to every character in a string, by far the best approach is to use a statement introduced by the new standard: the range for statement. This statement iterates through the elements in a given sequence and performs some operation on each value in that sequence. The syntactic form is

```
for (declaration : expression)
    statement
```
## 3.4 Iterators
### 3.4.1 Using iterators

* To iterate a container, the iterator should range from s.begin() and s.end().
* s.end() doesn't point to any element.
* When comparing it and s.end(), we should use != instead of <, since most iterators don't have < operator.
* For const iterators, the equivalent methods are: cbegin() and cend().

```
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << endl;
}
```

### 3.4.2 Iterator arithmetic
Iterators for string and vector support additional operations:

* iter + n
* iter - n
* iter1 += n
* iter1 -= n
* iter1 - iter2
* >, >=, <, <=

We can use it in binary search:

```
auto beg = text.begin(), end = text.end();
auto mid = text.begin() + (end - beg)/2; // original midpoint
```

### 3.5.3 Pointers and Arrays
#### std::begin() and std::end()
To make pointers behave like iterators, STL provides 2 functions: begin() and end().

```
int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
int *beg = begin(ia); // pointer to the first element in ia
int *last = end(ia);  // pointer one past the last element in ia
while (beg != last) {
    beg++;
}
```

## 3.6 Multidimensional Arrays
多维数组定义语法如下。我们也可以对数组使用range for语法。以下代码将二维数组中每个元素都乘以2.

```
int a[3][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
};

for (auto &i : a) {
    for (auto &j : i) {
        j *= 2;
    }
}   
```

用typedef或using定义多维数组类型：

```
using int_array = int[4]; // new style type alias declaration
typedef int int_array[4]; // equivalent typedef declaration
```


