#include <iostream>

using namespace std;

int main() {
	int bulan;
	cout << "masukkan angka 1 sampai 12";
	cin >> bulan;
	if (bulan == 1) {
		cout << "januari";
	} else if (bulan==2) {
		cout << "Februari";
	}
	return 0;
}
