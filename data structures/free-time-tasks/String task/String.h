#pragma once

const int sso_limit = 16;

class MyString
{
    char* str;
    int size;
    int capacity;

    char small_str[16];

    void copy(const MyString other);
    void clear();
    void resize();

    public:

    //Голяма четворка
    MyString():str(nullptr){};
    MyString(const MyString&);
    MyString& operator=(const MyString&);
    ~MyString();

    //move&&
    MyString(MyString&&);
    MyString& operator=(MyString&&);

    //параметричен конструктор
    MyString(const char*);

    //взеамме дължината
    int getLen() const
    {
        return size;
    }

    //вземаме char на позиция index
    char getChar(int index) const;

    //конкатенация
    MyString& operator+(const char&);
    MyString& operator+(const MyString&);

    //сравнения
    friend int compareLetters(const MyString& one, const MyString& two);
    friend int compareLength(const MyString& one, const MyString& two);
};