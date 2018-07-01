#include <string.h>
#include <iostream>
using namespace std;

class person {
public:
    person() { attr_name = new char[255];  }
    person(char *name, int age) : attr_age(age) {
        attr_name = new char[strlen(name)+1];
        strcpy(attr_name, name);
    }
    
    void print() {
        cout << "Person's name is: " << attr_name << "\nAge: " << attr_age << endl;
    }
    
private:
    char *attr_name;
    int attr_age;
};

class student : public person {
public:
    student() { attr_major = new char[255]; }
    student(char *name, int age, char *major, int year) : person(name, age), attr_year(year) {
        attr_major = new char[strlen(major)+1];
        strcpy(attr_major, major);
    }
    void print() {
        person::print();
        cout << "Major: " << attr_major << "\nYear: " << attr_year << endl;
    }
    
private:
    char *attr_major;
    int attr_year;
};

int main() {
    char name[] = "Methuselah";
    char major[] = "Theology";

    person test1(name, 365);
    student test2(name, 365, major, 4);
    test1.print();
    cout << endl;
    test2.print();

    return 0;
}
