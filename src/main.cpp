//  Copyright 2021 Nikita Naumov
#include "postfix.h"
#include <iostream>

int main() {
    std::string str("100 + 100 * 20.4");
    std::string strAns = infix2postfix(str);
    std::cout << strAns << "\n";  // the answer: 100 100 20.4 * +
    str = "10 + 5 * (4 / (10 - 2)) + 5";
    strAns = infix2postfix(str);
    std::cout << strAns;  // the answer: 10 5 4 10 2 - / * 5 + +
    return 0;
}