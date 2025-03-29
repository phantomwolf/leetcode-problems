# C++ STL Cheatsheet
## Vector
Create a 3D array of int and set initial values to 0:

```c++
vector<vector<vector<int>>> matrix(x, vector<vector<int>>(y, vector<int>(z, 0)));
```

## Map
Iterate an unordered_map:

```c++
unordered_map<int, int> map;
// Iterator
auto it = map.begin();
while (it != map.end()) {
    cout << "Key: " << it->first << ", Value: " << it->second << endl;
    it++;
}

// for-in loop
for (auto it : map) {
    cout << "Key: " << it->first << ", Value: " << it->second << endl;
}
// Modify value
for (auto& it : map) {
    it->second += 1;
}

// Structured binding
for (const auto [key,value] : m) {
    cout << "{" << key << "," << value << "}\n";
}
```

