#include <iostream>
using namespace std;

string getLampColor(int t) {
    if (t < 25) return "Red"; // special case before cycle starts

    int cycle = 103;
    int phase = (t - 25) % cycle; // position inside the cycle

    if (phase <= 19) return "Green";
    else if (phase <= 22) return "Yellow";
    else return "Red";
}

int main() {
    int t;
    char again;

    do {
        cout << "Enter the second: ";
        cin >> t;
        cout << "At second " << t << " the light is: "
             << getLampColor(t) << endl;

        cout << "Do you want to check another time? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "Program ended." << endl;
    return 0;
}
