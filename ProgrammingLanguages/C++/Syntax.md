# C++ Cheatsheet
## Initialization
Modern C++ support multiple ways to initialize a variable:

1. The traditional equal sign: `double d1 = 2.3`
2. The constructor: `vector<int> arr(size, initialValue)`
3. The braces: `vector<int> v{1, 2, 3, 4, 5, 6}`

My personal understanding is, we should use `=` for primitive types, use constructor for objects, and use braces for creating object literals.

```c++
  double d1 = 2.3;    // initialize d1 to 2.3
  double d2{2.3};     // initialize d2 to 2.3
  double d3 = {2.3};  // initialize d3 to 2.3 (the = is optional with { ... })

  complex<double> z = 1;  // a complex number with double scalars
  complex<double> z2{d1, d2};
  complex<double> z3 = {d1, d2};  // the = is optional with { ... }

  vector<int> v{1, 2, 3, 4, 5, 6};  // a vector of ints
```

## Constants

* const: meaning roughly “I promise not to change this value"
* constexpr: meaning roughly “to be evaluated at compile time”. However, a constexpr function can accept non-constant parameters, when it's not used in constexpr expression.
* consteval: meaning strictly evaluated at compile time.

```c++
constexpr int dmv = 17;                  // dmv is a named constant
int var = 17;                            // var is not a constant
const double sqv = sqrt(var);            // sqv is a named constant, possibly computed at run time

double sum(const vector<double>&);       // sum will not modify its argument (§1.7)
const double s1 = sum(v);                // OK: sum(v) is evaluated at run time
constexpr double s2 = sum(v);            // error: sum(v) is not a constant expression

constexpr double square(double x) { return x*x; }
constexpr double max1 = 1.4*square(17);     // OK: 1.4*square(17) is a constant expression
constexpr double max2 = 1.4*square(var);    // error: var is not a constant, so square(var) is not a constant
const double max3 = 1.4*square(var);        // OK: square's return value is used in a non-constant expression, thus its parameter can be a variable

consteval double square2(double x) { return x*x; }
constexpr double max1 = 1.4*square2(17);         // OK: 1.4*square2(17) is a constant expression
const double max3 = 1.4*square2(var);            // error: var is not a constant
```

## Enumerations
Traditional enum:

```c++
enum color {
    red = 10,
    black = 20,
    yellow = 30,
};
```

Enum class is the better way of defining enums(since C++ 11):

```c++
enum class Color { red, blue, green };
Color col = Color::red;
Color x1 = red;                 // error: which red?

int i = Color::red;      // error: Color::red is not an int
Color c = 2;             // initialization error: 2 is not a Color

// Conversion between enum and int
Color x = Color{5};  // OK, but verbose
Color y {6};         // also OK
int x = int(Color::red);
```

Enum class works similar to traditional enums, but it's type-safe and doesn't allow implicit conversions. However, if you do conversion explicitly, they can be converted to int:

```
    enum class Color {red, yellow, black};
    Color c = Color::yellow;
    cout << static_cast<int>(c) << endl;        // prints 1
```

## Header and Modules
Traditionally, C++ uses header files to separate definition and declaration. In C++ 20, a new language feature allows us to define modules:

```c++
export module Vector;   // defining the module called "Vector"
export class Vector {
public:
     Vector(int s);
     double& operator[](int i);
     int size();

private:
     double* elem;      // elem points to an array of sz doubles
     int sz;
};

Vector::Vector(int s)
    :elem{new double[s]}, sz{s}           // initialize members
{
}
```

## Return multiple values
A function can return only a single value, but you can return a class object with many members. This allows us to elegantly return many values.

```c++
struct Entry {
     string name;
     int value;
};

Entry read_entry(istream& is) {       // naive read function (for a better version, see §11.5)
     string s;
     int i;

     is >> s >> i;
     return {s,i};
}
```

Here, {s,i} is used to construct the Entry return value. Similarly, we can “unpack” an Entry’s members into local variables:

```c++
auto [n,v] = read_entry(is);
cout << "{ " << n << " , " << v << " }\n";
```

The auto [n,v] declares two local variables n and v with their types deduced from read_entry()’s return type. This mechanism for giving local names to members of a class object is called structured binding. We can use this syntax to iterate maps:

```c++
map<string,int> m;
// ... fill m ...
for (const auto [key,value] : m) {
    cout << "{" << key << "," << value << "}\n";
}

void incr(map<string,int>& m) {      // increment the value of each element of m
    for (auto& [key,value] : m)
        ++value;
}
```

## Error handling

```c++
int main(int argc, char* argv[]) {
    try {
        int length = 10;
        if (length > 5) {
            throw std::runtime_error{"error message"};
        }
    } catch (std::runtime_error& err) {
        cout << err.what() << endl;
    }
}
```

## Template
Syntax for template type argument and value argument:

```c++
template<typename T, int N>
struct Buffer {
     constexpr int size() { return N; }
     T elem[N];
     // ...
};
```

### Template argument deduction
Sometimes type arguments can be deducted by the compiler. For example:

```c++
pair<int,double> p = {1, 5.2};
```

is the same as:

```c++
pair p = {1, 5.2};       // p is a pair<int,double>
```

### Function objects
A function object is an object that's callable. We do so by implementing its operator() method.

```c++
template<typename T>
class LessThan {
    const T val;  // value to compare against

public:
    LessThan(const T& v) :val{v} { }
    bool operator()(const T& x) const { return x<val; } // call operator
};
```

We can call this object just like calling a function: `bool b1 = lti(n);   // true if n<42`.

Function objects are widely used as arguments to algorithms. Below is an example of using function object as the custom comparator of priority queue:

```c++
struct MinHeapCompare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first < b.first) {
            return false;
        }
        return true;
    }

int main(int argc, char* argv[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, MinHeapCompare> pq;
};
```

## Lambda
C++ 11 introduced lambda expressions. Syntax:

    [capture-clause] (parameters) -> return-type { 
        // definition
    }

Like other languages, lambda can **capture** external variables and read/write them. This is called closure. In C++, the capture clause determines how external variables are captured:

* `[]`: by default, lambda captures nothing.
* `[&]`: capture all external variables by reference.
* `[=]`: capture all external variables by value.
* `[a, &b]`: capture ‘a’ by value and ‘b’ by reference.

Examples:

```c++
    // Capture v1 and v2 by reference
    auto byRef = [&] (int m) {
        v1.push_back(m);
        v2.push_back(m);
    };
    // Capture v1 and v2 by value
    auto byVal = [=] (int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
    };
    // Capture v1 by reference and v2 by value
    auto mixed = [=, &v1] (int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
    };
    byRef(20);
    byVal(234);
    mixed(10);
```

Let’s understand what happened in this program:

* byRef captures all by reference. So pushing 20 will push it into original v1 and v2.
* byVal captures all by value. So pushing 234 will not do anything to original vectors.
* mixed captures v1 by reference and v2 by value. So pushing 10 will only push it into v1.

The **mutable** keyword here is used in capture by value lambdas only because, by default, value captured objects are const.

## finally
In C++, memory management must follow the RAII principle: clean up should be done in the destructors of objects. However, what if the clean up isn't related to a specific object? For example, I want to do some clean up at the end of a method. In Golang, we can use the `defer` keyword. In C++, we can implement something similar by ourselves:

```c++
template <class F>
struct FinalAction {
     explicit FinalAction(F f) : act(f) {}
     ~FinalAction() { act(); }
     F act;
};

// attribute [[nodiscard]] to ensure that users do not forget to copy a generated FinalAction into the scope for which its action is intended.
template <class F>
[[nodiscard]] auto finally(F f) {
    return FinalAction{f};
}
```

To use it, simpy pass something callable, such as a lambda function or a callable object, to the constructor of FinalAction. This will create an object of FinalAction, and when this object deconstructs, the lambda function will be called.

```c++
    void* p = malloc(n*sizeof(int));       // C-style
    auto act = finally([&]{free(p);});     // call the lambda upon scope exit
```

