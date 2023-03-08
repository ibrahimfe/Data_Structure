#include <iostream>
using namespace std;

int main() {
   int arr[] = {10, 20, 30, 40, 50}; // inisialisasi array
   int n = sizeof(arr) / sizeof(arr[0]); // hitung jumlah elemen dalam array
   int x;

   // sequential search
   cout << "Masukkan nilai yang akan dicari : ";
   cin >> x;  //Meminta user memasukkan data yang akan dicari
   int i;
   for (i = 0; i < n; i++) {
      if (arr[i] == x) {
         cout << "Nilai ditemukan pada indeks ke-" << i << endl;
         break;
      }
   }

   if (i == n) {
      cout << "Nilai tidak ditemukan dalam array" << endl;
   }

   return 0;
}

