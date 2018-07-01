#include <iostream>
using namespace std;

int main() {
    char name[255];
    int age;
    
    do {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        
        cout << "Hello " << name << ", next year you will be " << age+1 << "." << endl;
    } while (age > 0);
    
    return 0;
}
