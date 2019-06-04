# 4 Expressions
## 4.1 Fundamentals
### 4.1.1 Basic Concepts
#### Lvalues and Rvalues
In C, lvalues could stand on the left-hand side of an assignment whereas rvalues could not.

In C++, the distinction is less simple. In C++, an lvalue expression yields an object or a function. However, some lvalues, such as const objects, may not be the left-hand operand of an assignment. Moreover, some expressions yield objects but return them as rvalues, not lvalues. Roughly speaking, when we use an object as an rvalue, we use the object’s value (its contents). When we use an object as an lvalue, we use the object’s identity (its location in memory).

Operators differ as to whether they require lvalue or rvalue operands and as to whether they return lvalues or rvalues:

- = (assignment): lvalue as its left-hand operand and yields its left-hand operand as an lvalue
- & (address of): requires an lvalue operand and returns a pointer to its operand as an rvalue.
- * (deference) and [] (subscript): yield lvalues
- iterator increment and decrement: require lvalue operands and the prefix versions (which are the ones we have used so far) also yield lvalues.

Lvalues and rvalues also differ when used with decltype. When we apply decltype to an expression (other than a variable), the result is a reference type if the expression yields an lvalue. As an example, assume p is an int*. Because dereference yields an lvalue, decltype(*p) is int&. On the other hand, because the address-of operator yields an rvalue, decltype(&p) is int**, that is, a pointer to a pointer to type int.

## 4.11 Type conversions
### 4.11.3 Explicit Conversions
#### static_cast and dynamic_cast
dynamic_cast is similar to static_cast, except that it's executed at runtime, making it able to check if the cast is legal. For example, casting a derived class to its base class(upcast) is legal, while the opposite(downcast) isn't always legal.

Note: using dynamic_cast for upcasting is unnecessary.

#### const_cast
A const_cast changes only a low-level(pointer to const) const in its operand. Conventionally we say that a cast that converts a const object to a nonconst type “casts away the const.”

In g++, after const_cast, we can modify the variable pointed by the pointer:

```
char c = 'A';
const char *pc = &c;                // We can't modify c through pc
char *p = const_cast<char*>(pc);
*p = 'B';                           // But we can modify c through p
```

Only a const_cast may be used to change the constness of an expression. Trying to change whether an expression is const with any of the other forms of named cast is a compile-time error. Similarly, we cannot use a const_cast to change the type of an expression.

#### reinterpret_cast
A reinterpret_cast generally performs a low-level reinterpretation of the bit pattern of its operands.

```
int *ip;
char *pc = reinterpret_cast<char*>(ip);
```

#### old-style cast
Old-stype cast can behave like const_cast, a static_cast, or a reinterpret_cast.

```
type (expr); // function-style cast notation
(type) expr; // C-language-style cast notation
```
