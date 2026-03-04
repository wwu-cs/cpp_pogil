#include <iostream>
#include <list>
#include <utility>

using namespace std;

int main() {
    // std::list
    list<string> tasks = {"breakfast", "class", "lunch"};

    cout << "Initial tasks:" << endl;
    for (string task : tasks) {
        cout << "  " << task << endl;
    }

    tasks.push_front("wake up");  // add to front
    tasks.push_back("dinner");    // add to back
    tasks.pop_front();            // remove from front

    cout << "\nUpdated tasks:" << endl;
    for (string task : tasks) {
        cout << "  " << task << endl;
    }

    cout << "\nFront: " << tasks.front() << endl;
    cout << "Back:  " << tasks.back() << endl;

    // std::pair
    pair<string, int> student = {"Alice", 95};
    cout << "\nStudent: " << student.first << endl;
    cout << "Score:   " << student.second << endl;

    return 0;
}
