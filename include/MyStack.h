//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

#include <typeinfo>
#include <iostream>
#include <cstdio>
#include <ctime>


template <typename T> class MyStack {
 private:
    T *head;
    int topInd;
    unsigned int size;

 public:
    explicit MyStack(int num) {
        head = new T[num];
        this->size = num;
        this->topInd = 0;
    }

    MyStack(const MyStack& st) {
        this->topInd = st.topInd;
        this->size = st.size;
        this->head = new T[this->size];
        for (size_t i = 0; i < this->size; ++i) {
            this->head[i] = st.head[i];
        }
    }

    ~MyStack() {
        delete head;
    }

    bool isFull() const {
        if (topInd == size) {
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty() const {
        if (topInd == 0) {
            return true;
        } else {
            return false;
        }
    }

    void push(T elem) {
        if (isFull()) {
            throw -1;
        } else {
            head[topInd] = elem;
            topInd++;
        }
    }

    T pop() {
        if (isEmpty()) {
            throw -1;
        } else {
            topInd--;
            return head[topInd];
        }
    }

    T get() const {
        if (topInd <= 0) {
            throw -1;
        } else {
            return head[topInd-1];
        }
    }
};



#endif  //  INCLUDE_MYSTACK_H_
