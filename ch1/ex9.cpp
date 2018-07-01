#include <string.h>
#include <iostream>
using namespace std;

class string_demo {
public:
    string_demo(int n): len(n) { s = new char[n+1]; }
    void assign(const char *st) { strcpy(s, st); len = strlen(st); }
    int length() { return len; }
    void print() { cout << "Str is: " << s << "\nStr len is: " << len << endl; }
    // added function
    void reverse() {
        char temp;
        int i;
        for(i = 0; i < len/2; i++) {
            temp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = temp;
        }
    }
private:
    char *s;
    int len;
};

int main() {
    string_demo test(20);
    
    test.assign("baby's first class");
    test.print();
    test.reverse();
    test.print();
    
    
    return 0;
}
