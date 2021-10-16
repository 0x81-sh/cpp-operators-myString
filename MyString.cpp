#include "MyString.h"
#include <cstring>
#include <iostream>

void MyString::cpyAlloc(int sz) {
    sz++; //for \0

    char *old = str;
    str = new char[sz];

    strcpy(str, old);
    delete[] old;
}

MyString::MyString(const char *str) {
    this->length = strlen(str);

    this->str = new char[this->length + 1];
    strcpy(this->str, str);
}

MyString::MyString(const MyString &ref) {
    replace(ref);
}

MyString::~MyString() {
    delete[] str;
}

bool MyString::operator==(const MyString &ref) const {
    return strcmp(str, ref.str) == 0;
}

bool MyString::operator!=(const MyString &ref) const {
    return strcmp(str, ref.str) != 0;
}

int MyString::getLength() const {
    return length;
}

void MyString::show() const {
    for (int i = 0; i < length; i++) {
        std::cout << str[i];
    }
}

void MyString::showDebug() const {
    std::cout << "[";

    for (int i = 0; i < length; i++) {
        std::cout << (int) str[i] << "<" << str[i] << ">" <<  ";";
    }

    //stdio breaks if \0 is outputted, therefore this workaround is needed
    if (str[length] != '\0') {
        std::cout << (int) str[length] << "<" << str[length] << ">";
    } else {
        std::cout << "\\0";
    }

    std::cout << "]";
}

void MyString::append(const MyString &str) {
    this->length += strlen(str.str);
    cpyAlloc(this->length);
    strcat(this->str, str.str);
}

void MyString::addChar(char ch) {
    length++;
    cpyAlloc(length);
    str[length - 1] = ch;
    str[length] = '\0';
}

char MyString::getChar(int idx) const {
    if (!checkBounds(idx)) return '\0';
    return str[idx];
}

int MyString::compare(const MyString &str) const {
    return strcmp(this->str, str.str);
}

void MyString::toUpper() {
    for (int i = 0; i < length; i++) {
        str[i] = toupper(str[i]);
    }
}

void MyString::toLower() {
    for (int i = 0; i < length; i++) {
        str[i] = tolower(str[i]);
    }
}

void MyString::insertCharAt(char ch, int idx) {
    if (!checkBounds(idx)) idx = length - 1;

    length++;
    cpyAlloc(length);

    memmove(str + idx + 1, str + idx, length - idx); //strncpy does not have defined behaviour for overlapping source and destination, therefore memmove has to be used
    str[idx] = ch;
}

void MyString::insertStrAt(const MyString &str, int idx) {
    if (!checkBounds(idx)) idx = length - 1;
    cpyAlloc(str.length + length);

    memmove(this->str + idx + str.length, this->str + idx, this->length - idx); //strncpy does not have defined behaviour for overlapping source and destination, therefore memmove has to be used
    memcpy(this->str + idx, str.str, str.length); //use memcpy to avoid copying \0 into the middle of the string

    this->length += str.length;
    //manually add \0 in the correct position
    this->str[this->length] = '\0';
}

bool MyString::checkBounds(int idx) const {
    if (idx < 0 || idx >= this->length) return false;
    return true;
}

MyString& MyString::operator=(const MyString &ref) {
    if (&ref == this) return *this;

    delete[] str;
    replace(ref);

    return *this;
}

MyString MyString::operator+(const MyString &ref) const {
    MyString x(*this);
    x.append(ref);

    return x;
}

MyString &MyString::operator++() {
    addChar('*');
    return *this;
}

MyString MyString::operator++(int) {
    MyString cpy(*this);
    addChar('*');

    return cpy;
}

MyString MyString::operator-(const MyString &ref) const {
    MyString cpy(ref);
    MyString that(*this);

    char *ptr = nullptr;
    for (int i = 0; cpy.length > 0; i++) {
        ptr = strstr(that.str, cpy.str);

        if (ptr == nullptr) {
            cpy.pop();
        } else {
            break;
        }
    }

    if (ptr == nullptr) return MyString(*this);

    //      char*     char* + int          int         - (char* - char*)  - int        + int
    memmove(ptr, ptr + cpy.length, that.length - (ptr - that.str) - cpy.length + 1);
    that.length -= cpy.length;

    return that;
}

void MyString::replace(const MyString &ref) {
    this->length = ref.length;

    this->str = new char[this->length + 1];
    strcpy(this->str, ref.str);
}

void MyString::pop() {
    str[length - 1] = '\0';
    length--;
    cpyAlloc(length);
}
