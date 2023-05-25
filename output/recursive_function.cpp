#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    // Stop condition
    if (n == 0)
        return 0;

    // Stop condition
    if (n == 1 || n == 2)
        return 1;

    // Recursion function
    else
        return (fib(n - 1) + fib(n - 2));
}
// Factorial function
int f(int n)
{
    // Stop condition
    if (n == 0 || n == 1)
        return 1;

    // Recursive condition
    else
        return n * f(n - 1);
}

int FPB(int m, int n)
{
    if (m == 0)
        return n;
    else if (m < n)
        return FPB(n, m);
    else
        return FPB(m % n, n);
}
int power(int m, int n)
{
    if (n == 1 || n == 0)
        return m;
    else
        return m * power(m, n - 1);
}
void towers(int n, char awal, char akhir, char antara)
{
    if (n == 1)
        printf("Pindahkan piringan 1 dari %c ke %c\n", awal, akhir);
    else
    {
        towers(n - 1, awal, antara, akhir);
        printf("Pindahkan piringan %d dari %c ke %c\n", n, awal, akhir);
        towers(n - 1, antara, akhir, awal);
    }
}

int main()
{
    int angka;
    cout << "Masukkan angka : ";
    cin >> angka;

    cout << fib(angka) << endl;
    cout << f(angka) << endl;

    cout << "Masukkan Angka yang kedua :";
    int angka2;
    cin >> angka2;
    cout << FPB(angka, angka2)
}