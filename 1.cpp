#include <iostream>
using namespace std;

int main () {
    int a,b,c;
    cout << "masukkan bilangan pertama = ";
    cin >> a;
    cout << "masukkan bilangan kedua = ";
    cin >> b;

    for (int i = b; i>0; i--) {
        if (b%a == 0) {
            cout << "* ";
        } else {
            cout << b<<" ";
        }
        b--;
    }
}