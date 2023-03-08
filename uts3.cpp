#include <iostream>
using namespace std;

int main () {
    int a,b,sum;
    sum = 0;
    cout << "Masukkan bilangan pertama = ";
    cin >> a;

    for (int i = 0; i<a; i++) {
        cout << "masukkan bilangan kedua = ";
        cin >> b;
        sum = sum + b;
    }
    cout << sum;
}