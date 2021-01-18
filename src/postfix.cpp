//  Copyright 2021 Nikita Naumov
#include "postfix.h"
#include "MyStack.h"
#include <typeinfo>

bool isOperator(char symb) {
    switch (symb) {
        case '(':
            return true;
            break;
        case ')':
            return true;
            break;
        case '*':
            return true;
            break;
        case '/':
            return true;
            break;
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        default:
            return false;
            break;
    }
}

int setPriority(char symb) {
    switch (symb) {
        case '(':
            return 0;
            break;
        case ')':
            return 1;
            break;
        case '+':
            return 2;
            break;
        case '-':
            return 2;
            break;
        case '*':
            return 3;
            break;
        case '/':
            return 3;
            break;
        default:
            return 4;
            break;
    }
}

std::string infix2postfix(std::string str) {
    std::string changedStr;
    MyStack<std::string> opStack(1000);
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            continue;
        }
        if (isOperator(str[i])) {
            if (str[i] == '(' || opStack.isEmpty()) {
                opStack.push(std::string(1, str[i]));
            } else {
                if (setPriority(str[i]) > setPriority(opStack.get()[0])) {
                    opStack.push(std::string(1, str[i]));
                } else {
                    while (!opStack.isEmpty() &&
                        setPriority(opStack.get()[0]) >= setPriority(str[i])) {
                        changedStr += opStack.pop() + " ";
                    }
                    if (str[i] == ')') {
                        if (opStack.get()[0] == '(') {
                            opStack.pop();
                        }
                    } else {
                       opStack.push(std::string(1, str[i]));
                    }
                }
            }
        } else {
            std::string tmp("");
            while (str[i] != ' ' && i < str.size()) {
                tmp += str[i];
                i++;
                if (i < str.size() && str[i] == ')') {
                    i--;
                    break;
                }
            }
            changedStr += tmp + ' ';
        }
    }
    while (!opStack.isEmpty()) {
        if (opStack.get() == "(") {
            opStack.pop();
            continue;
        }
        changedStr += opStack.pop() + " ";
    }
    if (!changedStr.empty()) {
        changedStr.erase(changedStr.size() - 1, 1);
    }
    return changedStr;
}
