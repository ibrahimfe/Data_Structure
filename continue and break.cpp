#include <iostream>

using namespace std;

int main () {
    int i;
    cout << "Masukkan Sebuah angka";
    cin >> i;
    for (int i; i < 10; i++) {
  if (i == 4) {
    continue;
  }
  cout << i << "\n";
}
}