#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    int MAX;   
    T* data;   
    int lastElement;

public:
    Stack(int maxSize) {
        MAX = maxSize;
        data = new T[MAX];
        lastElement = -1;
    }

    void push(T item) {
        if (lastElement == MAX - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++lastElement] = item;
    }

    T pop() {
        if (empty()) {
            cout << "Stack underflow!" << endl;
            return T();
        }
        return data[lastElement--];
    }

    T peek() {
        if (empty()) return T();
        return data[lastElement];
    }

    bool empty() {
        return lastElement == -1;
    }
};
#endif