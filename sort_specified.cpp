#include <iostream>
#include <vector>

using namespace std;

void radix_sort(vector<int>& v) {
	int mask = 0x1;
	for(int i  = 0; i < 3; ++i) {
		vector<int> zero, one;
		for(int n : v) {
			if(n & mask) {
				one.push_back(n);
			} else {
				zero.push_back(n);
			}
		}
		v.clear();
		v.insert(v.begin(), zero.begin(), zero.end());
		v.insert(v.end(), one.begin(), one.end());
		mask <<= 1;
	}
}

int main() {
	vector<int> v{ 1, 0, 0, 1, 2, 0, 2, 2, 1, 1, 0, 1, 2, 0, 2 };
	radix_sort(v);
	
	for(int n : v) {
		cout << n;
	}
	cout << endl;

	return 0;
}

