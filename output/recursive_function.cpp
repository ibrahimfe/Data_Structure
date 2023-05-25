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

int main()
{
    int angka;
    cout << "Masukkan angka : ";
    cin >> angka;

    cout << fib(angka) << endl;
    cout << f(angka) << endl;
}