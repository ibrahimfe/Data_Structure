#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n / 3600 << endl;
    cout << n % 3600 / 60 << endl;
    cout << n % 60;
}

