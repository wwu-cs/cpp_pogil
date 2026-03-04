#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> scores = {92, 78, 85, 91, 63};

    // Traditional index-based for loop
    cout << "Traditional loop: ";
    for (int i = 0; i < (int)scores.size(); i++) {
        cout << scores.at(i) << " ";
    }
    cout << endl;

    // Range-based for loop (value copy)
    cout << "Range-based loop: ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;

    // Attempting to modify (won't change original)
    for (int score : scores) {
        score += 5;  // modifies local copy only
    }
    cout << "After copy loop:  ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;

    // Range-based for loop with reference (modifies original)
    for (int& score : scores) {
        score += 5;  // modifies original vector
    }
    cout << "After ref loop:   ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
