#include <iostream>
#include "MyString.h"

int main() {
    const char word1[] = {'h','e','l','l','o','\0'};
    const char word2[] = {'t','h','e','r','e','\0'};
    //const char word3[] = {'e','l','l','\0'};
    MyString string1 = MyString(word1);
    MyString string2 = MyString(word2);
    // MyString string5 = MyString(word3);
    // MyString string3 = MyString(string1);
    // MyString string4 = MyString();
    // MyString string6 = string1 + string2;
    // string3 = string1;
    // string1 += string2;
    // std::cout << string1.find(string5) << std::endl;
    // std::cout << string1.data() << std::endl;
    // std::cout << string2.data() << std::endl;
    // std::cout << string6.data() << std::endl;
    return 0;
}