#include <iostream>
using namespace std;

int main() {
    int i;
    
    cout << "i\tsqr(i)\tcube(i)" << endl;
    cout << "-----------------------" << endl;
    
    for(i = 0; i < 21; i++) {
        cout << i << "\t" << i * i << "\t" << i * i * i << endl;
    }
    
    return 0;
}
