#include <iostream>

using namespace std;

class A {
public:
    void FunctionA() {cout << "FunctionA" << endl;}
    virtual void FunctionB() {cout << "A - FunctionB" << endl;}
    static void FunctionC() {cout << "A - FunctionC" << endl;}
};

class B : public A {
public:
    void FunctionB() {cout << "B - FunctionB" << endl;}
    int FunctionD() {
        cout << "B - FunctionD" << endl;
        return 0;
    }
};

int main() {
    B *b = nullptr;
    b->FunctionA();
    b->FunctionB();
    b->FunctionC();
    b->FunctionD();
    return 0;
}
