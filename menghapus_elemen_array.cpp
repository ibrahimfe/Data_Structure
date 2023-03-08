#include <iostream>

using namespace std;

int main() {
    // Deklarasi array awal
    int arr[5] = {1, 2, 3, 4, 5};
    int arrSize = 5;
    int deleteIndex;

    // Menampilkan array awal
    cout << "Array awal: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Meminta user untuk memasukkan indeks elemen yang ingin dihapus
    cout << "Masukkan indeks elemen yang ingin dihapus: ";
    cin >> deleteIndex;

    // Menghapus elemen dari array
    for (int i = deleteIndex; i < arrSize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arrSize--;

    // Menampilkan array setelah elemen dihapus
    cout << "Array setelah elemen dihapus: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

