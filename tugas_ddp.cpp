#include <iostream>
using namespace std;

void pertambahan (int x, int y) {
    cout << "Ini adalah hasil pertambahan angka tersebut : " << x + y << endl;
}
void pengurangan (int x, int y) {
    cout << "Ini adalah hasil Pengurangan angka tersebut : " << x - y << endl;
}
void perkalian (int x, int y) {
    cout << "Ini adalah hasil perkalian angka tersebut : " << x * y << endl;
}
void pembagian (int x, int y) {
    cout << "Ini adalah hasil pembagian dari angka tersebut : " << x / y << endl;
}
void menu() {
    cout << "-----------------------\nA. Pertambahan \nB. Pengurangan \nC. Perkalian \nD. Pembagian \nE. Selesai \nMasukkan Fungsi yang akan digunakan : ";
}
int main () {
    double angka1, angka2;
    char option;

    cout << "Kamu disini akan memasukkan 2 angka \nMasukkan angka yang pertama : ";
    cin >> angka1;
    cout << "Masukkan angka yang kedua : ";
    cin >> angka2;
    cout << "Ini adalah angka mu : " << angka1 << ", " << angka2 << endl;
    menu();
    cin >> option;

    while (option != 'E') {
        switch (option) {
            case 'A' :
                pertambahan(angka1, angka2);
                break;
            case 'B' :
                pengurangan(angka1, angka2);
                break;
            case 'C' :
                perkalian(angka1, angka2);
                break;
            case 'D' :
                pembagian(angka1, angka2);
                break;
            default :
                break;
        }
        menu();
        cin >> option;

    }
}
