// TODO: Implement this source file
#include <iostream>
#include "MyString.h"
#include <stdexcept>

MyString::MyString() : m_size(0), m_cap(1), string(new char[1]) {
    string[0] = '\0';
}

MyString::MyString(const MyString& str) : m_size(str.m_size), m_cap(str.m_cap), string(nullptr) {
    string = new char[str.m_cap];
    for(int i = 0; i < str.m_size; i++) {
        this->string[i] = str.string[i];
    }
}

MyString::MyString (const char* s) : m_size(0), m_cap(1), string(nullptr) {
    bool nullChar = false;
    int index = 0;

    if(s == nullptr) {
        string = new char[m_cap];
        string[0] = '\0';
    }
    else {
        while(!nullChar) {
           if(s[index] == '\0') {
               nullChar = true;
          }
          else {
               index++;
          }
        }

        m_size = index;
        m_cap = m_size + 1;
        string = new char[m_cap];
        for(int i = 0; i < m_cap; i++) {
            string[i] = s[i];
        }
    }
}

MyString::~MyString() {
    delete[] string;
    string = nullptr;
    m_cap = 0;
    m_size = 0;
}

void MyString::resize (size_t n) {
    size_t capConst = m_cap;
    if(capConst > n) {
        int diff = m_cap - n;
        char* newString = new char[diff];
        for(int i = 0; i < diff; i++) {
            newString[i] = string[i];
        }
        m_size = n - 1;
        m_cap = n;
        delete[] string;
        string = newString;
    }
    else if(capConst < n) {
        char* newString = new char[n];
        int nInt = n;
        for(int i = 0; i < nInt; i++) {
            if(i < m_size) {
                newString[i] = string[i];
            }
            else {
                newString[i] = '\0';
            }            
        }
        m_size = n - 1;
        m_cap = n;
        delete[] string;
        string = newString;
    }
}

size_t MyString::capacity() const noexcept {
    return m_cap;
}

size_t MyString::size() const noexcept {
    return m_size;
}

size_t MyString::length() const noexcept {
    return m_size;
}

const char* MyString::data() const noexcept {
    return string;
}

bool MyString::empty() const noexcept {
    if(m_size == 0) {
        return true;
    }
    else {
        return false;
    }
}

const char& MyString::front() const {
    return this->string[0];
}

const char& MyString::at (size_t pos) const {
    int posInt = pos;
    if(posInt >= m_size or posInt < 0) {
        throw std::invalid_argument("out of bounds");
    }
    return this->string[pos];
}

void MyString::clear() noexcept {
    char* newString = new char[0];
    delete[] string;
    string = newString;
    m_size = 0;
    m_cap = 1;
}

size_t MyString::find (const MyString& str, size_t pos) const noexcept {
    int posInt = pos;
    int strSize = str.size();
    // std::cout << str.size() << std::endl;
    // std::cout << m_size << std::endl;
    for(int i = posInt; i < m_size; i++) {
        int count = 0;
        for(int j = 0; j < strSize; j++) {
            // std::cout << "String 1: " << string[i + count] << std::endl;
            // std::cout << "String 2: " << str.at(j) << std::endl;
            // std::cout << "Count: " << count << std::endl;
            if(!(string[i + count] == str.at(j))) {
                break;
            }
            else {
                count++;
            }
            //std::cout << "here" << std::endl;
            if(count == strSize) {
                //std::cout << "match found" << std::endl;
                return i;
            }
        }
    }
    //std::cout << "match not found" << std::endl;
    return -1;
}

std::ostream& operator<< (std::ostream& os, const MyString& str) {
    return os;
}

MyString& MyString::operator= (const MyString& str) {
    if(this == &str) {
        //std::cout << "Same object" << std::endl;
        return(*this);
    }
    if(this->string != nullptr) {
        delete[] this->string;
        this->string = nullptr;
        this->m_size = 0;
        this->m_cap = 0;
    }

    (*this).resize(str.m_cap);

    for(int i = 0; i < m_cap; i++) {
        this->string[i] = str.string[i];
    }
    
    return (*this);
}

MyString& MyString::operator+= (const MyString& str) {
    int tempSize = this->m_size;
    (*this).resize(this->m_size + str.m_cap);

    // std::cout << this->m_size << std::endl;
    // std::cout << this->m_cap << std::endl;
    
    int index = 0;
    for(int j = tempSize; j < this->m_cap; j++) {
        this->string[j] = str.string[index];
        index++;
    }

    for(int i = 0; i < this->m_cap; i++) {
        // std::cout << this->string[i];
    }
    // std::cout << std::endl;

    return (*this);
}

bool MyString::operator== (const MyString& rhs) noexcept {
    if(this->m_size != rhs.m_size or this->m_cap != rhs.m_cap) {
        return false;
    }
    for(int i = 0; i < this->m_size; i++) {
        if(this->string[i] != rhs.string[i]) {
            return false;
        }
    }
    return true;
}

/*MyString MyString::operator+ (const MyString& rhs) : m_size(0), m_cap(1), string(nullptr) {
    string = new char[lhs.m_size + rhs.m_cap];
    for(int i = 0; i < lhs.m_size; i++) {
        this->string[i] = lhs.string[i];
    }        
    for(int j = 0; j < rhs.m_cap; j++) {
        this->string[j + lhs.m_size] = rhs.string[j];
    }
    this->m_size = lhs.m_size + rhs.m_size;
    this->m_cap = this->m_size + 1;
}*/