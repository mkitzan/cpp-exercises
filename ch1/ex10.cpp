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
    void print(int pos, int k) {
        char temp;
        temp = s[(pos+k)%len];
        s[(pos+k)%len] = '\0';
        cout << s + sizeof(char) * pos << endl;
        s[(pos+k)%len] = temp;
    }
private:
    char *s;
    int len;
};

int main() {
    string_demo test(20);
    
    test.assign("baby's first class");
    test.print();
    test.print(5, 3);
    
    
    return 0;
}
