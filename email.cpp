#include <iostream>
using namespace std;
int main ()
{
    string email,name;
    int pembatas;
    cout << "masukkan email anda : " ;
    cin >> email;

    pembatas = email.find('@');
    name = email.substr(0,pembatas);
    cout << "Username anda adalah : " << name;
    
    return 0;
} 
