#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {

    Person var;
    var.name = "Goofy";
    var.age = 63;

    cout << var.name << endl << var.age << endl;


    Person var2;
    cout << "Person's name: ";
    cin >> var2.name;
    cout << "Person's age: ";
    cin >> var2.age;

    cout << var2.name << endl << var2.age << endl;

}