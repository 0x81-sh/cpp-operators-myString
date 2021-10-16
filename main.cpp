#include <iostream>
#include "MyString.h"
#include <cassert>

void test_assign(const MyString &a, const MyString &b_res);
void test_add(const MyString &a, const MyString &b, const MyString &res);
void test_prefixIncrement(const MyString &a, const MyString &res);
void test_postfixIncrement(const MyString &a, const MyString &res);
void test_subtract(const MyString &a, const MyString &b, const MyString &res);

void test_append(const MyString &a, const MyString &b, const MyString &res);
void test_addChar(const MyString &a, char x, const MyString &res);
void test_toUpper(const MyString &a, const MyString &res);
void test_toLower(const MyString &a, const MyString &res);
void test_insertChar(const MyString &a, char x, int idx, const MyString &res);
void test_insertStr(const MyString &a, const MyString &b, int idx, const MyString &res);

int main() {
    test_assign(MyString("test"), MyString("str"));
    test_add(MyString("test"), MyString("str"), MyString("teststr"));
    test_prefixIncrement(MyString("test"), MyString("test*"));
    test_postfixIncrement(MyString("test"), MyString("test*"));
    test_subtract(MyString("some test string"), MyString("test "), MyString("some string"));
    test_subtract(MyString("some test string"), MyString("test xyz"), MyString("some string"));

    test_append(MyString("test"), MyString("str"), MyString("teststr"));
    test_addChar(MyString("test"), 'a', MyString("testa"));
    test_toUpper(MyString("sOmE tEsT sTrInG"), MyString("SOME TEST STRING"));
    test_toLower(MyString("sOmE tEsT sTrInG"), MyString("some test string"));
    test_insertChar(MyString("acd"), 'b', 1, MyString("abcd"));
    test_insertStr(MyString("ad"), MyString("bc"), 1, MyString("abcd"));

    return 0;
}

void test_assign(const MyString &a, const MyString &b_res) {
    MyString cpy(a);
    cpy = b_res;

    assert(cpy == b_res);
}
void test_add(const MyString &a, const MyString &b, const MyString &res) {
    assert(a + b == res);
}
void test_prefixIncrement(const MyString &a, const MyString &res) {
    MyString cpy(a);

    assert(++cpy == res);
}
void test_postfixIncrement(const MyString &a, const MyString &res) {
    MyString cpy(a);
    cpy++;

    assert(cpy == res);
}
void test_subtract(const MyString &a, const MyString &b, const MyString &res) {
    assert(a - b == res);
}

void test_append(const MyString &a, const MyString &b, const MyString &res) {
    MyString cpy(a);
    cpy.append(b);

    assert(cpy == res);
}
void test_addChar(const MyString &a, char x, const MyString &res) {
    MyString cpy(a);
    cpy.addChar(x);

    assert(cpy == res);
}
void test_toUpper(const MyString &a, const MyString &res) {
    MyString cpy(a);
    cpy.toUpper();

    assert(cpy == res);
}
void test_toLower(const MyString &a, const MyString &res) {
    MyString cpy(a);
    cpy.toLower();

    assert(cpy == res);
}
void test_insertChar(const MyString &a, char x, int idx, const MyString &res) {
    MyString cpy(a);
    cpy.insertCharAt(x, idx);

    assert(cpy == res);
}
void test_insertStr(const MyString &a, const MyString &b, int idx, const MyString &res) {
    MyString cpy(a);
    cpy.insertStrAt(b, idx);

    assert(cpy == res);
}