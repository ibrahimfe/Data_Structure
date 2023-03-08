#include <iostream>
using namespace std;

int main () {
    int a,max,min;

    cout << "masukkan bilangan = ";
    cin >> a;
    max = a;
    min = a;
    while (a>0) {
        cout << "Masukkan bilangan = ";
        cin >> a;

        if (a<=0) {
            break;
        } else if (a > max) {
            max = a;
        } else if (a<min) {
            min = a;
        }
        
    }
    cout << max << " "<< min << endl;
    cout << max/min;
}