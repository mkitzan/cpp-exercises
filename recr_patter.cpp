#include <iostream>

using namespace std;

void pattern(int n) {
	cout << n << ' ';
	if(n > 0) {
		pattern(n - 5);
		cout << n << ' ';
	}	
}

int main() {
	pattern(16);
	cout << endl;

	pattern(-16);
	cout << endl;

	pattern(0);
	cout << endl;

	return 0;
}

