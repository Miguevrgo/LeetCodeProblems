#include <stack>
#include <utility>

using namespace std;

class MinStack {
    stack<int> elem;
public:
    MinStack() {
    }

    void push(int val) {
        if (elem.empty()) {
            elem.push(val);
            elem.push(val);
        }
        else{
            int minimum = min(val,elem.top());
            elem.push(val);
            elem.push(minimum);
        }
    }

    void pop() {
        elem.pop();
        elem.pop();
    }

    int top() {
        int minimum = elem.top();
        elem.pop();
        int value = elem.top();
        elem.push(minimum);
        return value;
    }

    int getMin() {
        return elem.top();
    }
};
//class MinStack {
//    stack<pair<int,int>> elem;
//public:
//    MinStack() {
//    }
//
//    void push(int val) {
//        if (elem.empty()){
//            elem.push(make_pair(val,val));
//        }
//        else{
//            elem.push(make_pair(val,min(val,elem.top().second)));
//        }
//    }
//
//    void pop() {
//        elem.pop();
//    }
//
//    int top() {
//        return elem.top().first;
//    }
//
//    int getMin() {
//        return elem.top().second;
//    }
//};
