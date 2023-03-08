#include <iostream>
using namespace std;

int main () {
    int candles,result;
    cin >> candles;
    if (candles < 0) {
        cout << "cant do that";
    } else {
        result = (candles + 1) * 9;
        cout << result;
    }
    return 0;
}