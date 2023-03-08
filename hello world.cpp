#include <iostream>

using namespace std;

int main() {
	int hasil;
	int x = 22;
	cout << "masukkan angka : ";
	cin >> x;
	
	while (x<=87) {
		hasil = hasil + x;
		x++;
	}
	cout << hasil;
	return 0;
}
