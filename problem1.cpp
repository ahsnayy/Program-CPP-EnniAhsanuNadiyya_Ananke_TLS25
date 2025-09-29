#include <iostream>
#include <cmath>
using namespace std;

int indexEven(int x) {
    int sign = (x < 0) ? -1 : 1;
    int n = abs(x);
    int even = 0;

    while (n > 0) {
        int digit = n % 10;
        even = even * 10 + digit;
        n = n / 10;
    }

    return even * sign;
}

int main() {
    int n;
    
    cout << "Enter number of array element: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " number of array separated by space: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += indexEven(arr[i]);
        } else {
            sum += arr[i];
        }
    }

    cout << "Array sum: " << sum << endl;

    return 0;
}
