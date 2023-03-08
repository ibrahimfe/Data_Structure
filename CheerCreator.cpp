#include <iostream>
using namespace std;

int main () {
    int point,cost;
    cin >> point >> cost;
    point = point/12;
    if (point - cost > 0) {
        cout << "Buy it!";
    } else {
        cout << "Try Again";
    }
    return 0;
}