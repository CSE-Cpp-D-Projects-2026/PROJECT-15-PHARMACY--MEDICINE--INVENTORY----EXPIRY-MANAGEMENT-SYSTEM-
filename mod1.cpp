#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Test {
    int id;
    string name;
    double price;
};

class Patient {
private:
    int id, age;
    string name, contact;
    static int totalPatients;

public:
    Patient()
{
    id = 0;
    age = 0;
    name = "";
    contact = "";
}    

Patient(int i, string n, int a, string c) : id(i), age(a), name(n), contact(c)
{
 totalPatients++;
}
    
Patient(const Patient &p)
{
    id = p.id;
    age = p.age;
    name = p.name;
    contact = p.contact;
}