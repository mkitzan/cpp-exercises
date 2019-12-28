#include <iostream>
#include <vector>

using namespace std;

struct url { uint8_t id[6]; };

struct url shorten(int id, vector<uint8_t>& map) {
	int i{ 0 }, mod = map.size();
	struct url value{ 0 };

	while(id) {
		value.id[i++] = map[id % mod];
		id /= mod;
	}
	
	return value;
}

int main() {
	vector<uint8_t> map;
	for(int i = 0; i < 10; ++i) {
		map.push_back('0' + i);
	}
	for(int i = 0; i < 26; ++i) {
		map.push_back('a' + i);
	}
	for(int i = 0; i < 26; ++i) {
		map.push_back('A' + i);
	}

	struct url value = shorten(123456789, map);
	cout << value.id << endl;

	return 0;
}

