#include <iostream>
#include <stack>

using namespace std;

// Min Stack.
// https://leetcode.com/problems/min-stack/description/
class MinStack {
private:
    stack<int> o, m;

public:
    MinStack() : o{}, m{} {}

    void push(int value) {
        o.push(value);
        if (m.empty() || m.top() > value) {
            m.push(value);
        }
    }

    void pop() {
        if (o.top() == m.top()) {
            m.pop();
        }
        o.pop();
    }

    int top() {
        return o.empty() ? -1 : o.top();
    }

    int getMin() {
        return m.empty() ? -1 : m.top();
    }
};

int main(void) {
    // MinStack* obj = new MinStack();
    // obj->push(value);
    // obj->pop();
    // int param_3 = obj->top();
    // int param_4 = obj->getMin();

    MinStack ms{};
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << " "; // return -3
    ms.pop();
    cout << ms.top() << " ";    // return 0
    cout << ms.getMin() << endl; // return -2

    return 0;
}
