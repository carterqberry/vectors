//
// Created by carter quesenberry on 3/26/23.
//

#ifndef VECTORPROJECT_TEST_H
#define VECTORPROJECT_TEST_H

#include <cstddef>
#include <iostream>

using std::size_t;

namespace {
    size_t nPass{0};
    size_t nFail{0};
    void do_fail(const char* text, const char* fileName, long lineNumber) {
        std::cout << "FAILURE: " << text << " in file " << fileName
                  << " on line " << lineNumber << std::endl;
        ++nFail;
    }
    void do_test(const char* condText, bool cond, const char* fileName, long
    lineNumber) {
        if (!cond)
            do_fail(condText, fileName, lineNumber);
        else {
#ifdef verbose
            std::cout << "Test passed on line " << lineNumber << std::endl;
#endif
            ++nPass;
        }
    }
#ifdef succeed
    void succeed_() {
++nPass;
}
#endif
    void report_() {
        std::cout << "\nTest Report:\n\n";
        std::cout << "\tNumber of Passes = " << nPass << std::endl;
        std::cout << "\tNumber of Failures = " << nFail << std::endl;
    }
}
#define test_(cond) do_test(#cond, cond, __FILE__, __LINE__)
#define fail_(text) do_fail(text, __FILE__, __LINE__)
#define throw_(text,T) \
try { \
text; \
std::cout << "THROW "; \
do_fail(#text,__FILE__,__LINE__); \
} catch (T&) { \
++nPass; \
} catch (...) { \
std::cout << "THROW "; \
do_fail(#text,__FILE__,__LINE__); \
}
#define nothrow_(text) \
try { \
text; \
++nPass; \
} catch (...) { \
std::cout << "NOTHROW "; \
do_fail(#text,__FILE__,__LINE__); \
}
#endif
