#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float houses, result;
    cin >> houses;

    if (houses > 2) {
        cout << ceil((2/houses)*100);
    } else
    cout << "3 is the minimum";

    return 0;
}