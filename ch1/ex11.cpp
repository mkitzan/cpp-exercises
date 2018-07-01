#include <string.h>
#include <iostream>
using namespace std;

class string_demo {
public:
    string_demo(int n): len(n), max(n) { s = new char[n+1]; }
    void assign(const char *st) { strcpy(s, st); len = strlen(st); }
    int length() { return len; }
    void print() { cout << "Str is: " << s << "\nStr len is: " << len << endl; }
    // added function
    void operator*(const int n) {
        if(n * len > max) {
            cerr << "Not enough room for multiplied string" << endl;
        } else {
            int i;
            char temp[len+1];
            
            strcpy(temp, s);
            
            for(i = 0; i < n; i++) {
                strncat(s, temp, len);
            }
        }
    }
private:
    char *s;
    int len;
    // added parameter
    int max;
};

int main() {
    string_demo test(255);
    
    test.assign("baby's first class");
    test.print();
    test * 3;
    test.print();
    
    return 0;
}
