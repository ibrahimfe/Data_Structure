#include<iostream>
#include <cstring>
using namespace std;

int main() {
	string tanggal,hari,bulan,tahun;
	cout << "Masukkan Sebuah Tanggal lahir kamu dalam format yyyy-mm-dd : ";
	cin >> tanggal;
	char tanggal_lahir[tanggal.length()+1];
	strcpy(tanggal_lahir, tanggal.c_str());
	
	int size_tanggal_lahir = sizeof(tanggal_lahir) / sizeof(char);
	
	for (int a = 8; a < size_tanggal_lahir; a++) {
		hari= hari + tanggal_lahir[a];
	}
	for (int a = 5; a < (size_tanggal_lahir)-4; a++) {
		bulan = bulan + tanggal_lahir[a];
	}
	for (int a = 0; a < (size_tanggal_lahir)-7; a++) {
		tahun = tahun + tanggal_lahir[a];
	}
//		if (bulan == "01") {
//			cout << "Januari";
//		}
	cout << "anda lahir di tanggal " << hari << "bulan " << bulan << " tahun " << tahun << endl;
	return 0;
}
