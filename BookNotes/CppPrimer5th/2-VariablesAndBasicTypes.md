# 2 Variables and Basic Types
## 2.1 Primitive Built-in Types
Some typical primitive types(linux x64):

```
long long       8 bytes
long            8 bytes
int             4 bytes
short           2 bytes
char            1 byte
wchar_t         4 bytes(on Windows, it's 2 bytes and holds UTF-16 code points)
char16_t        2 bytes(type for UTF-16 character representation)
char32_t        4 bytes(type for UTF-32 character representation)
float           4 bytes(single precision floating point type, Usually IEEE-754 32 bit floating point type)
double          8 bytes(double precision floating point type. Usually IEEE-754 64 bit floating point type)
long double     16 bytes(extended precision floating point type)
std::size_t     8 bytes
```

## 2.4 const qualifier
const variables can be initialized by non-const ones(indicating its value isn't determined at compile-time).

By default, const variables are local to a file, meaning each file can have a const variable with the same name but different value. To define a single instance of a const variable, we use the keyword extern on both its definition and declaration(s):

```
// file_1.cc defines and initializes a const that is accessible to other files
extern const int bufSize = fcn();
// file_1.h
extern const int bufSize; // same bufSize as defined in file_1.cc
```

### 2.4.1 References to const
A reference to a const variable must be a const reference. A const reference to a non-const variable can avoid changing it by mistake.

```
const int ci = 1024;
const int &r1 = ci;   // ok: both reference and underlying object are const
r1 = 42;              // error: r1 is a reference to const
int &r2 = ci;         // error: non const reference to a const object
```

Terminology: const Reference is a Reference to const. C++ programmers tend to abbreviate the phrase “reference to const” as “const reference.” Technically speaking, there are no const references. A reference is not an object, so we cannot make a reference itself const. Indeed, because there is no way to make a reference refer to a different object, in some sense all references are const.

### 2.4.2 Pointers and const(low-level const)
A pointer can be a pointer to const and a const pointer at the same time.

语法：const放最前面的是pointer to const；const紧跟着 * 的是const pointer
#### Pointer to const
A pointer to const is a pointer which can't change the value of the variable it points to, but the value of the pointer itself can be changed(like pointing to another variable). Also known as low-level const.

```
double pi1 = 3.14;
double pi2 = 3.1415926;
const double *ptr = &pi1;
ptr = &pi2;     // ok. The pointer can point to another variable
*ptr = 386;     // error. cannot use ptr to change the value
```

#### const pointer(high-level const)
A const pointer, just like any other const variable, can't be changed. It can't pointer to another variable. Also known as high-level const.

```
int errNumb = 0;
int *const curErr = &errNumb;  // curErr will always point to errNumb
const double pi = 3.14159;
const double *const pip = &pi; // pip is a const pointer to a const object
```

### 2.4.4 constexpr and constant expressions
A constant expression is an expression whose value cannot change and that can be evaluated at compile time. A literal is a constant expression. A const object that is initialized from a constant expression is also a constant expression.

In a large system, it can be difficult to determine (for certain) that an initializer is a constant expression. After C++11, we can ask the compiler to verify that a variable is a constant expression by declaring the variable in a constexpr declaration. Variables declared as constexpr are implicitly const and must be initialized by constant expressions:

```
constexpr int mf = 20;        // 20 is a constant expression
constexpr int limit = mf + 1; // mf + 1 is a constant expression
constexpr int sz = size();    // ok only if size is a constexpr function
```

Generally, it is a good idea to use constexpr for variables that you intend to use as constant expressions.

#### Pointers and constexpr
See below codes:

```
const int *p = nullptr;     // p is a pointer to a const int
constexpr int *q = nullptr; // q is a const pointer to int
```

Despite appearances, the types of p and q are quite different; p is a pointer to const, whereas q is a constant pointer. The difference is a consequence of the fact that constexpr imposes a top-level const (§ 2.4.3, p. 63) on the objects it defines.

## 2.5 Dealing with Types
### 2.5.1 Type Aliases
Unlike Golang, type aliases are just aliases, not new types.

Unlike #define, the alias created is in the end.

```
typedef double wages;   // wages is a synonym for double
typedef wages base, *p; // base is a synonym for double, p for double*
```

C++11 introduced a new way to do it:

```
using SI = Sales_item;  // SI is a synonym for Sales_item
```

#### Pointers, const , and Type Aliases
Declarations that use type aliases that represent compound types and const can yield surprising results.

```
typedef char *pstring;
const pstring cstr = 0; // cstr is a constant pointer to char
const pstring *ps;      // ps is a pointer to a constant pointer to char
```

### 2.5.2 The auto Type Specifier
Since C++11, we can let the compiler figure out the type for us by using the auto type specifier.

```
// the type of item is deduced from the type of the result of adding val1 and val2
auto item = val1 + val2; // item initialized to the result of val1 + val2
auto i = 0, *p = &i;      // ok: i is int and p is a pointer to int
auto sz = 0, pi = 3.14;   // error: inconsistent types for sz and pi
```

### 2.5.3 The decltype Type Specifier
Sometimes we want to define a variable with a type that the compiler deduces from an expression but do not want to use that expression to initialize the variable. For such cases, the new standard introduced a second type specifier, decltype, which returns the type of its operand.

```
decltype(f()) sum = x; // sum has whatever type f returns
```
