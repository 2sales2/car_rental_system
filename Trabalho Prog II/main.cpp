#include "Person.h"
#include "NaturalPerson.h"
#include "LegalPerson.h"
#include "Car.h"
#include "Date.h"
#include "RentRegister.h"
#include "Agency.h"

int main() {

    Person p1;
    LegalPerson p2;
    NaturalPerson p3;
    Car c1;
    Date d1;
    RentRegister r1;

    r1.generatetRID();
    d1.setDM(1,1);
    std::cout << d1.getDay() << "\n" << d1.getMonth() << "\n";
    std::cout << r1.getRentID() << "\n";


}