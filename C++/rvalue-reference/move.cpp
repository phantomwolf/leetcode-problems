#include <iostream>
#include <string>

using namespace std;

typedef struct Credential Credential;

struct Credential
{
    string login;
    string passwd;
};

class MyClass
{
public:
    MyClass(string login, string passwd)
    {
        this->data          = new Credential;
        this->data->login   = login;
        this->data->passwd  = passwd;
    }

    virtual ~MyClass()
    {
        cout << "destructing login: " << this->data->login << endl;
        delete this->data;
    }

    // Copy constructor
    MyClass(const MyClass &other)
    {
        cout << "MyClass: copy constructor" << endl;
        this->data          = new Credential;
        this->data->login   = other.data->login;
        this->data->passwd  = other.data->passwd;
    }
    
    // Copy assignment
    MyClass &operator=(const MyClass &other)
    {
        cout << "MyClass: copy assignment" << endl;
#if __cplusplus < 201103L
        // 在C++11以前，存在一种copy & swap策略，即将other复制一份，然后用swap函数将新对象与现对象交换，最后新对象自动销毁。
        MyClass tmp(other);     // re-use copy-constructor
        this->swap(tmp);        // swap
        return *this;
#else
        // C++ 11风格。需要定义move assignment操作符
        MyClass tmp(other);         // re-use copy-constructor
        *this = std::move(tmp);     // re-use move-assignment
        return *this;
#endif
    }


#if __cplusplus >= 201103L
    // Move constructor
    MyClass(MyClass &&other) noexcept :
        data(other.data)
    {
        cout << "move constructor..." << endl;
        other.data = nullptr;
    }

    // Move assignment
    MyClass &operator=(MyClass &&other) noexcept
    {
        cout << "move assignment..." << endl;
        Credential *tmp = other.data;
        other.data      = this->data;
        this->data      = tmp;
        return *this;
    }

#endif

    void show(void)
    {
        cout << "login: " << this->data->login << ", passwd: " << this->data->passwd << endl;
    }

private:
#if __cplusplus < 201103L
    void swap(MyClass &other)
    {
        cout << "swaping..." << endl;
        Credential *tmp = other.data;
        other.data      = this->data;
        this->data      = tmp;
    }
#endif

    Credential *data;
};


int main(int argc, char *argv[])
{
    MyClass obj1("user1", "baka");
    MyClass obj2("user2", "aniki");
    
    cout << "obj1 - ";
    obj1.show();
    cout << "obj2 - ";
    obj2.show();

    obj1 = obj2;

    cout << "obj1 - ";
    obj1.show();
    return 0;
}
