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

    template<typename T>
    TestCase& check_equal(T x, T y);

    template<typename T>
    TestCase& check_different(T x, T y);

    template<typename R , typename T , typename S>
    TestCase& check_function(R func, T x, S y);

    template <typename T>
    TestCase& check_output(T x , string str);

    void print();


};

template<typename T>
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

template<typename T>
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

        return *this;
}

template <typename R , typename T , typename S>
TestCase& TestCase::check_function(R func , T x, S y) {
    T temp = func(x);
    if(temp == y)
        passed++;
    else{
        failed++;
        ostringstream save1, save2;
        save1 << temp;
        save2 << y;
        string msg = "Function should return " + save2.str() + " but returned " + save1.str() + "!";;
        write2stream(msg);
    }
    return *this;
}


template <typename T>
TestCase& TestCase::check_output(T x, string str) {
    ostringstream out;
    out << x;
    if (out.str() == str)
    {
        passed++;
    }
    else{
        failed++;
        string msg = "string value should be " + str + " but is " + out.str();
        write2stream(msg);

    }

    return (*this);
}