#include <iostream>
#include <string>


using namespace std;

// Headers
string toString (double);
int toInt (string);
double toDouble (string);

int main() {
    string nama, name;
    int tanggalLahir, bulanLahir, tahunLahir;
    int tanggalSekarang, bulanSekarang, tahunSekarang;
    int totalHariLahir, totalHariSekarang, selisih;
    int uTahun, uBulan, uTanggal;
    
    cout << "Masukkan Tanggal Lahir " << endl;
    cin >> tanggalLahir;
    cout << "Masukkan Bulan lahir" << endl;
    cin >> bulanLahir;
    cout << "Masukkan Tahun Lahir" << endl;
    cin >> tahunLahir;
    cout << "Masukkan Tanggal hari ini" << endl;
    cin >> tanggalSekarang;
    cout << "Masukkan  bulan sekarang" << endl;
    cin >> bulanSekarang;
    cout << "Masukkan Tahun Sekarang " << endl;
    cin >> tahunSekarang;

        totalHariLahir = tanggalLahir + bulanLahir * 30 + tahunLahir * 365;
        totalHariSekarang = tanggalSekarang + bulanSekarang * 30 + tahunSekarang * 365;
        selisih = totalHariSekarang - totalHariLahir;

    uTahun = (int) ((double) selisih / 365);
    uBulan = (int) ((double) (selisih % 365) / 30);
    uTanggal = selisih % 365 % 30;
    
    cout << "Umur kamu adalah " << uTahun << " Tahun " << uBulan << " Bulan " << uTanggal << " Hari" << endl;
    return 0;
}
