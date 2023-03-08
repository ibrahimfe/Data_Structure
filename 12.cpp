#include <iostream>
using namespace std;

int main () {
    float orders, sum;
    cin >> orders;

    sum = orders * 5;
    if (orders > 1) {
        sum = sum - (sum * 0.1);
        cout << sum + (sum * 0.07);
    } else {
        cout << sum + (sum * 0.07);
    }
}