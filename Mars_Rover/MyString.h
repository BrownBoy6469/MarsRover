// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString {
    private: 
        int m_size;
        int m_cap;
        char* string;
    public:
        // constructors
        MyString();
        MyString(const MyString& str);
        MyString (const char* s);

        // destuctor
        ~MyString();

        // functions
        void resize (size_t n);
        size_t capacity() const noexcept;
        size_t size() const noexcept;
        size_t length() const noexcept;
        const char* data() const noexcept;
        bool empty() const noexcept;
        const char& front() const;
        const char& at (size_t pos) const;
        void clear() noexcept;
        size_t find (const MyString& str, size_t pos = 0) const noexcept;

        // operators        
        MyString& operator= (const MyString& str);
        MyString& operator+= (const MyString& str);        
        //MyString operator+ (const MyString& rhs);
        bool operator== (const MyString& rhs) noexcept;
};


std::ostream& operator<< (std::ostream& os, const MyString& str);

#endif