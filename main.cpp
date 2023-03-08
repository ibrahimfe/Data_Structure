#include <iostream>
#include <string>

using namespace std;

int main() {
    string arr[3]; // Deklarasi array dengan tipe data string dan ukuran 3

    // Inisialisasi elemen array
    arr[0] = "apel";
    arr[1] = "jeruk";
    arr[2] = "mangga";
    
    // Mengganti value indeks pertama
    arr[0] = "anggur";

    /* Variabel memiliki value gabungan dari 2 array
       dan 1 kalimat string "dan"  */
    arr[2] = arr[0] + " dan " + arr[1];
    
 

    for (int i = 0; i < 3; i++) {
        cout << &arr[i] << endl;
    }

    return 0;
}
