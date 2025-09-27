#include "Person.h"
#include <iostream>

std::string Person::getName() {return name;}

std::string Person::getAdress() {return adress;}
std::string Person::getPhone() {return phone_number;}
int Person::getID() {return system_id;}

//--- Setters ---
void Person::setName(std::string aName) {name = aName;}

void Person::setAdress(std::string anAdress) {adress = anAdress;}

void Person::setPhone(std::string aPhone) {phone_number = aPhone;}

void Person::generateID() { system_id = generate_new_ID();}

std::string Person::toString(){
    std::string output 
    = 
        "NOME : " + name + "\n" +
        "ENDERECO : " + adress + "\n" + 
        "TELEFONE : " + phone_number + "\n" +
        "ID : " + std::to_string(system_id) + "\n" ;

    return output ;
}

int generate_new_ID() {

    // Códigos de clientes terão prefixo 1 no inicio de cada ID
    std::string new_id{"1"};

    std::random_device seed{};
    std::default_random_engine engine{seed()};
    std::uniform_int_distribution generator{1000,9999};

    int ID = generator(engine);

    new_id += std::to_string(ID);

    return std::stoi(new_id);

}
