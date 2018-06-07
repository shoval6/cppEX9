#pragma once
#include <string>
#include <iostream>
#include <sstream>


using namespace std;


class TestCase {

private:
    string testName;
    ostream &os;
    int passed, failed;
    void write2stream(string msg);

public:

    TestCase(string testName, ostream &os) : testName(testName), os(os),passed(0) , failed(0) {};

    template<class T>
    TestCase& check_equal(T x, T y);

    template<class T>
    TestCase& check_different(T x, T y);

    template<class T , class R>
    TestCase& check_function(R(*func)(T s), T x, R y);

    template <class T>
    TestCase& check_output(T x , string str);

    void print();




};

template<class T>
TestCase &TestCase::check_equal(T x, T y) {
    if (x == y)
        passed++;
    else {
        failed++;
        ostringstream save1, save2;
        save1 << x;
        save2 << y;
        string msg = save1.str() + " should equal " + save2.str() + "!";
        write2stream(msg);
    }

    return *this;
}

template<class T>
TestCase& TestCase::check_different(T x, T y) {
    if (x != y)
        passed++;
    else {
        failed++;
        ostringstream save1, save2;
        save1 << x;
        save2 << y;
        string msg = save1.str() + " should'nt equal " + save2.str() + "!";
        write2stream(msg);    }

}

template <class T , class R>
TestCase& TestCase::check_function(R (*func)(T), T x, R y) {
    T temp = (*func)(x);
    if(temp == y)
        passed++;
    else{
        failed++;
        ostringstream save1, save2;
        save1 << x;
        save2 << y;
        string msg = "Function should return " + save1.str() + " but returned " + save2.str() + "!";;
        write2stream(msg);
    }

    return *this;
}


template <class T>
TestCase& TestCase::check_output(T x, string str) {
    ostringstream save;
    save << x;
    if (save.str() == str)
        passed++;
    else
        failed++;
}


