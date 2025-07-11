#include <iostream>

int foo(int a, int b) {
    if (a > 0 && b > 0) {
        return a + b;
    }
    if (a < 0 && b < 0) {
        return -a -b;
    }
    return 0;
}

int bar(int a) {
    int ret = 0;
    switch(a) {
        case 0:
            ret = 0;
            break;
        case 1:
            ret = 1;
            break;
        case 2:
            ret = 2;
            break;
        default:
            ret = -1;
            break;
    }
    return ret;
}

int main(int argc, char* argv[]) {
    // This is a dead branch, which will not be covered.
    if (argc > 100) {
        return -1;
    }
    int a = 1;
    int b = 2;
    std::cout << "foo(1, 2) = " << foo(a, b) << std::endl;
    std::cout << "bar(1) = " << bar(a) << std::endl;

    // New test cases for full coverage
    std::cout << "--- New Test Cases ---" << std::endl;

    // Test cases for foo()
    std::cout << "foo(-1, -2) = " << foo(-1, -2) << std::endl; // Covers a < 0 && b < 0
    std::cout << "foo(0, 0) = " << foo(0, 0) << std::endl;     // Covers the default return
    std::cout << "foo(1, -1) = " << foo(1, -1) << std::endl;   // Covers a > 0 and b <= 0
    std::cout << "foo(-1, 1) = " << foo(-1, 1) << std::endl;   // Covers a < 0 and b >= 0

    // Test cases for bar()
    std::cout << "bar(0) = " << bar(0) << std::endl;       // Covers case 0
    std::cout << "bar(2) = " << bar(2) << std::endl;       // Covers case 2
    std::cout << "bar(3) = " << bar(3) << std::endl;       // Covers default case

    return 0;
}