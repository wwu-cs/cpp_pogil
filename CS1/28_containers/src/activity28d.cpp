#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
    // std::queue (FIFO - First In, First Out)
    queue<string> waitlist;
    waitlist.push("Alice");
    waitlist.push("Bob");
    waitlist.push("Carol");

    cout << "Processing waitlist:" << endl;
    while (!waitlist.empty()) {
        cout << "  Serving: " << waitlist.front() << endl;
        waitlist.pop();
    }

    // std::deque (double-ended queue)
    deque<int> dq;
    dq.push_back(3);
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(4);

    cout << "\nDeque contents:" << endl;
    for (int val : dq) {
        cout << "  " << val << endl;
    }

    cout << "\nFront: " << dq.front() << endl;
    cout << "Back:  " << dq.back() << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "\nAfter removing front and back:" << endl;
    for (int val : dq) {
        cout << "  " << val << endl;
    }

    return 0;
}
