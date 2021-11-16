#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Stack Last In First Out
int main() {
    stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.pop();
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}
#################################
// Queue First In First Out
int main()
{
    queue<int> queue;
    queue.push(10);
    queue.push(20);
    cout << queue.size() << endl;
    cout << queue.front() << endl;
    cout << queue.back() << endl;
    queue.pop();
    while (!queue.empty()) {
        cout << g.front() << endl;
        g.pop();
    }
    return 0;
}
