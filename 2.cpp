#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

int main () {
    int a, b, lebar_int[2], panjang_int[2], luas_int[2];
    string luas_string[2], panjang_string[2], lebar_string[2];
    
    for (b = 0; b <= 1; b++) {
        a = 0;
        cin >> luas_string[b];
        while (luas_string[b][a] != ',') {
            panjang_string[b] = panjang_string[b] + luas_string[b][a];
            a++;
        } 
        a++;
        while (a < luas_string[b].length()) {
            lebar_string[b] = lebar_string[b] + luas_string[b][a];
            a++;
        }
        stringstream convert_panjang (panjang_string[b]);
        convert_panjang >> panjang_int[b];
        stringstream convert_lebar (lebar_string[b]);
        convert_lebar >> lebar_int[b];
    }

    if (panjang_int[0] * lebar_int[0] >= panjang_int[1] * lebar_int[1]) {
        cout << "Apartment A";
    } else {
        cout << "Apartment B";
    }
}