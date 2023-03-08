#include<iostream>
#include <cstring>
using namespace std;

int main() {
	string tanggal,hari,bulan,tahun;
	//membuat variabel string untuk menyimpan data dari user dan untuk Output ke user
	
	cout << "Masukkan Sebuah Tanggal lahir kamu dalam format yyyy-mm-dd : ";
	cin >> tanggal;
	
	char tanggal_lahir[tanggal.length()+1];
	//membuat variabel char dengan array sebanyak panjang kata dari variabel string tanggal
	
	strcpy(tanggal_lahir, tanggal.c_str());
	//menyalin nilai dari variabel tanggal ke variabel char tanggal_lahir
	
	int size_tanggal_lahir = sizeof(tanggal_lahir) / sizeof(char);
	//membuat variabel integer untuk pengoprasian Loop FOR
	
	for (int a = 8; a < size_tanggal_lahir; a++) {	// a=8 karena pada format yyyy-mm-dd nilai hari
		hari= hari + tanggal_lahir[a];				 // diwakilkan setelah nilai ke 8 sampai nilai terakhir
	}
	for (int a = 5; a < (size_tanggal_lahir)-4; a++) {	// a=5 karena pada format yyyy-mm-dd nilai bulan
		bulan = bulan + tanggal_lahir[a];				// diwakilkan setelah nilai ke 5 dan sebelum nilai ke 8
	}
	for (int a = 0; a < (size_tanggal_lahir)-7; a++) {	// a=0 karena pada format yyyy-mm-dd nilai tahun
		tahun = tahun + tanggal_lahir[a];				// diwakilkan setelah nilai pertama dan sebelum nilai ke 5
	}
		if (bulan == "01") {
			bulan = "Januari";
		} else if (bulan == "02") {
				bulan = "Februari";
			} else if (bulan == "03") {
					bulan = "Maret";
				} else if (bulan == "04") {
						bulan = "April";
					} else if (bulan == "05") {
							bulan = "Mei";
						} else if (bulan == "06") {		// mengubah nilai 01-12 pada variabel bulan menjadi nama nama bulan
								bulan = "Juni";
							} else if (bulan == "07") {
									bulan = "Juli";
								} else if (bulan == "08") {
										bulan = "Agustus";
									} else if (bulan == "09") {
											bulan = "September";
										} else if (bulan == "10") {
												bulan = "Oktober";
											} else if (bulan == "11") {
													bulan = "November";
												} else if (bulan == "12") {
														bulan = "Desember";
												}

	cout << "anda lahir di tanggal " << hari << "bulan " << bulan << " tahun " << tahun << endl;
	
	return 0;
}
