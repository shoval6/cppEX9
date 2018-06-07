#include "TestCase.hpp"


void TestCase::write2stream(string msg) {

    string res = testName + ": failed in test #"+std::to_string(passed+failed)+":"+msg;
    os<<res<<endl;
}


void TestCase::print() {

    os << testName << ": " << std::to_string(failed) << " failed, ";
    os << to_string(passed) << " passed, ";
    os << to_string(passed+failed) << " total." << endl << "---" << endl;

}
