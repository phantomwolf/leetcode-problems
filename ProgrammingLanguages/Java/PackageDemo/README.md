# Package
Package in Java is a mechanism to encapsulate a group of classes, sub packages and interfaces. Packages are used for:

- Preventing naming conflicts. For example there can be two classes with name Employee in two packages, college.staff.cse.Employee and college.staff.ee.Employee
- Making searching/locating and usage of classes, interfaces, enumerations and annotations easier
- Providing controlled access: protected and default have package level access control. A protected member is accessible by classes in the same package and its subclasses. A default member (without any access specifier) is accessible by classes in the same package only.
- Packages can be considered as data encapsulation (or data-hiding).

## Package的特性

- public: 该成员可被所有class访问；private: 该成员只能在该class内部被访问；default: 该成员只能在同一个package里访问；protected: 该成员可以在同一个package里和subclass里访问。
- 可以避免命名冲突

# 示例
假设我们公司域名为www.snowwolf.com，要创建一个名为com.snowwolf.somepackage的package，其中包含一个class: SomeClass。

建立以下目录结构，用于存储java源码文件:

```
$ tree sources
sources/
├── Application.java
└── com
    └── snowwolf
        └── somepackage
            └── SomeClass.java
```

向环境变量CLASSPATH里添加一个路径，用于存储class文件(java字节码)，例如./classes：

```
export CLASSPATH="$CLASSPATH:classes"
mkdir -p classes
```

编译SomeClass.java：

```
$ java -d "./classes" sources/com/snowwolf/somepackage/SomeClass.java
$ tree classes
classes/
└── com
    └── snowwolf
        └── somepackage
            └── SomeClass.class
```

可以看到java自动按照package的名字，按路径生成了相应的class文件。其他的文件在import这个package时，也会从$CLASSPATH/com/snowwolf/somepackage里寻找相应的class文件。编译Application.java：

```
$ java -d "./classes" sources/Application.java
$ tree classes
classes/
├── Application.class
└── com
    └── snowwolf
        └── somepackage
            └── SomeClass.class
```

之后Application就可以运行了：

```
$ cd classes
$ java Application
```

