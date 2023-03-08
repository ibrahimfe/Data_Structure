#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Masukkan Nilai N = ";
    cin >> n;

    int a = 1; //suku pertama
    int b = 1; //suku ke dua
    int d = 0; //total 

    if (n == 0) {
        cout << "1 ";
    } else if (n >= 1) {
        cout << "1 ";
        cout << " + 1"; 
    } else if (n == 1) {
        d = 2;
    }
    for (int i = 2; i<n; i++) {
        cout<< a;
    }
    cout << " = " << d;
}
