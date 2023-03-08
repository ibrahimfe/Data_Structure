#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

float bill;
string food;

void menu(string food) {
    for (int i = 0; i < 4; i++) {
        cin >> food;
        if (food == "Nachos") {
            bill = bill + 6;
        } else if (food == "Pizza") {
            bill = bill + 6;
        } else if (food == "Cheeseburger") {
            bill = bill + 10;
        } else if (food == "Water") {
            bill = bill + 4;
        } else if (food == "Coke") {
            bill = bill + 5;
        } else {
            bill = bill + 5;
        }
    }
    cout << bill+(bill*7/100);
    
}

int main() {
    bill = 0;

    menu(food);

    return 0;
}