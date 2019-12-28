#include <iostream>
#include <vector>

using namespace std;

int check(vector<int>& v) {
	int sum, mask = 0x1, num = 0;	

	for(int i = 0; i < sizeof(int) * 8; ++i) {
		sum = 0;
		for(int n : v) {
			sum += (mask & n);
		}
		num |= sum % (3 << i);
		mask <<= 1;
	}

	return num;
}

int main() {
	vector<int> v{1, 1, 1, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5};

	cout << check(v) << endl;

	return 0;
}

