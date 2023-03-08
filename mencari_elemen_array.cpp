#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int searchElement;
    int arrSize = 5;
    int foundIndex = -1;

    // Meminta elemen yang akan dicari
    cout << "Masukan elemen yang ingin dicari : ";
    cin >> searchElement;

    // Mencari elemen pada array
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == searchElement) {
            foundIndex = i;
            break;
        }
    }

    // Output indeks elemen yang ditemukan
    if (foundIndex != -1) {
        cout << "Elemen " << searchElement << " ditemukan pada indeks " << foundIndex << endl;
    } else {
        cout << "Elemen " << searchElement << " tidak ditemukan" << endl;
    }
}
