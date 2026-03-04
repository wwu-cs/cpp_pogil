#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    // std::map
    map<string, int> population;
    population["Seattle"] = 750000;
    population["Bellingham"] = 90000;
    population["Olympia"] = 52000;
    population["Seattle"] += 1000;  // update existing entry

    cout << "City populations:" << endl;
    for (pair<string, int> city : population) {
        cout << "  " << city.first << ": " << city.second << endl;
    }

    cout << "\nSeattle exists: " << population.count("Seattle") << endl;
    cout << "Portland exists: " << population.count("Portland") << endl;

    // std::set
    set<int> scores = {85, 92, 78, 92, 85, 100};
    scores.insert(73);
    scores.insert(92);  // duplicate, won't be added

    cout << "\nUnique scores:" << endl;
    for (int score : scores) {
        cout << "  " << score << endl;
    }

    cout << "\nSet size: " << scores.size() << endl;

    return 0;
}
