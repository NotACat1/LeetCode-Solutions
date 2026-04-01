#include <stack>

class MyQueue {
private:
    std::stack<int> in_stack, out_stack;

    void move() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }
public:
    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        move();
        auto val = out_stack.top();
        out_stack.pop();
        return val;
    }

    int peek() {
        move();
        return out_stack.top();
    }

    bool empty() {
        move();
        return in_stack.empty() && out_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */