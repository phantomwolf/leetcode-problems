#include <iostream>
#include <cstring>
#include <cstdlib>
#include <deque>
#include <ctime>

using namespace std;

class MyString
{
public:
    // members
    unsigned long length;

    // constructor
    MyString(const char *s)
    {
        this->id = rand() % 1024;
        cout << this->id << ": constructor from char*" << endl;
        this->length = strlen(s);
        this->data = new char[this->length];
        memcpy(this->data, s, sizeof(char) * strlen(s));
    }
    
    // destructor
    virtual ~MyString()
    {
        cout << this->id << ": destructor" << endl;
        delete[] this->data;
    }

    // copy constructor
    MyString(const MyString &other)
    {
        this->id = rand() % 1024;
        cout << this->id << ": copy constructor" << endl;
        this->length = other.length;
        this->data = new char[this->length];
        memcpy(this->data, other.data, sizeof(char) * this->length);
    }

    // assignment operator
    MyString &operator=(const MyString &other)
    {
        cout << this->id << ": assignment operator" << endl;
        // copy & swap MyString tmp(other);
        MyString tmp(other);
        this->swap(tmp);
    }

    // move constructor
    MyString(MyString &&tmp)
    {
        this->id = rand() % 1024;
        cout << this->id << ": move constructor" << endl;
        this->move(static_cast<MyString &&>(tmp));
    }

    // move assignment operator
    MyString &operator=(MyString &&tmp)
    {
        this->id = rand() % 1024;
        cout << this->id << ": move assignment operator" << endl;
        this->move(static_cast<MyString &&>(tmp));
        return *this;
    }

    void move(MyString &&tmp)
    {
        cout << this->id << ": move" << endl;
        this->length = tmp.length;
        this->data = tmp.data;
        tmp.length = 0;
        tmp.data = nullptr;
    }

    void swap(MyString &other)
    {
        cout << this->id << ": swap" << endl;
        std::swap(this->length, other.length);
        std::swap(this->data, other.data);
    }

protected:
    char *data;
    int id;
};


int main()
{
    srand(time(NULL));
    MyString s("baka");
    deque<MyString> q;
    cout << "push back" << endl;
    q.push_back(std::move(s));
    cout << "get front" << endl;
    MyString front = std::move(q.front());
    cout << "pop front" << endl;
    q.pop_front();
    cout << "after pop" << endl;
}
