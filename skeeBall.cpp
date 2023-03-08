#include <iostream>
using namespace std;

int main() {
    int score,gun;
    float tickets;
    cin >> score >> gun;
    
    tickets = score/12;
    if (tickets >= gun) {
        cout << "Buy it!";
    } else {
        cout << "Try again";
    }

}