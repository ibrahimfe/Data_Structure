#include <iostream>

using namespace std;

int main() {
	char answer = 'y';
	string name;
	
	cout << "input nama";
	cin >> name;
	
	for (int i = 0; i < name.length();i++) {
		if (name[i] == 'A') {
			name[i] = 'N';
		}
		
	}
	cout << name << endl;
	cout << "end loop";
}

