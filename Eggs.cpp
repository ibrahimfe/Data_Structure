#include <bits/stdc++.h>  
using namespace std;  

int total = 0;
void SplitStr(string str)
{
    string s = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            cout << s << endl;
            s = "";
        }
        else {
            s = s + x;
        }
    }
    if (s == "Lettuce") {
        total += 5;
    } else if (s == "Carrot") {
        total +=4;
    } else if (s == "Mango") {
        total +=9;
    } else if (s == "Cheeseburger") {
        total +=0;
    } 
    if (total > 10) {
        cout << "Come on Down!";
    } else {
        cout << "Time to wait";
    }

}
 
int main()
{
    string text;
    SplitStr(text);
    return 0;
}
