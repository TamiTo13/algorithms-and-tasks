#include <iostream>
#include <cstring>
#include "String.h"




void MyString::copy(const MyString other)
{
    if(other.size< sso_limit)
    {
        size=other.size;
        strcpy(small_str, other.small_str);
    }
    else
    {
        size = other.size;
        capacity = other.capacity;
        str = new char[capacity];
        strcpy(str,other.str);  //strcpy_s?
    }    
}

void MyString::clear()
{
    if(str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }
}

void MyString::resize()
{
    char* buffer = new char[capacity];
    strcpy(buffer, str);

    capacity <<=1;
    delete[] str;
    str = new char[capacity];
    strcpy(str, buffer);

    delete[] buffer;

}

MyString::MyString(const MyString& other)
{
    copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

MyString::~MyString()
{
    clear();
}

MyString::MyString(const char* other)
{
    if(strlen(other) < sso_limit)
    {
        strcpy(small_str, other);
    }
    else
    {
        size = strlen(other);
        capacity = 32;
        while (capacity < size) capacity<<=1;

        str = new char[capacity];
        strcpy(str,other);
    }
}

char MyString::getChar(int index) const
{
    try
    {
        return str[index-1];
    }
    catch(...)
    {
        std::cerr << "Wrong index";
        return ' ';
    }
    
}

MyString& MyString::operator+(const char& symbol)
{   
    if(size+1 > sso_limit)
    {
        if(size+1 >= capacity) resize();
         str[++size] = symbol;
    }
    else
    {
        small_str[++size] = symbol;
    }
}

MyString& MyString::operator+(const MyString& other)
{
    while(size+other.size <= capacity)
    {
        resize();
    }

    size += other.size;

    strcat(str,other.str);
}

int compareLetters(const MyString& one, const MyString& two)
{
    return strcmp(one.str, two.str);
}

int compareLength(const MyString& one, const MyString& two)
{
    if(one.size == two.size) return 0;

    return one.size > two.size?  1:  -1;
}


MyString::MyString(MyString&& other)
{
    copy(other);
    other.clear();
}

 MyString& MyString::operator=(MyString&& other)
 {
    if(this != &other)
    {
        clear();
        copy(other);
        other.clear();
    }

    return *this;
 }

