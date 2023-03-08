#include <iostream>
using namespace std;

class buku
{
public:
    string judul, penerbit, jml_halaman, kota_diterbiitkan;
    string data() {
        cout << "Masukkan Judul : "; cin >> judul;
        cout << "Masukkan penerbit : "; cin >> penerbit;
        cout << "Masukkan Judul halaman : "; cin >> jml_halaman;
        cout << "Masukkan Kota Diterbitkan : "; cin >> kota_diterbiitkan;
        return judul, penerbit, jml_halaman, kota_diterbiitkan;
    }
    void cetak(){
        cout << "judul buku kamu adalah : " << judul << endl;
        cout << "Penerbit dari buku kamu adalah : " << penerbit << endl;
        cout << "Halaman dari buku tersebut adalah : " << jml_halaman << endl;
        cout << "Kota diterbitkan dari buku tersebut adalah : " << kota_diterbiitkan << endl;
    }
};

int main() {
    string x;
    buku fiksi;
    buku non_fiksi;
    cout << "apakah kamu ingin membaca buku ? (ya/tidak): "; cin >> x;
    if (x == "ya") {
        fiksi.data();
        fiksi;
    }

   
}
