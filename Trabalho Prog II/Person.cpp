#include "Person.h"
#include <iostream>

// --- Getters ---
std::string Person::getName()const {return name;}
std::string Person::getAdress()const {return adress;}
std::string Person::getPhone()const {return phone_number;}
int Person::getID()const {return system_id;}
int Person::getRelationship()const {return costumer_relationship;}

//--- Setters ---
void Person::setName(std::string aName) {name = aName;}
void Person::setAdress(std::string anAdress) {adress = anAdress;}
void Person::setPhone(std::string aPhone) {phone_number = aPhone;}
void Person::generateID() { system_id = generate_new_ID();}

void Person::setRelationship(int level) {

    if (level < 0 || level > 5) {
        costumer_relationship = 0;
    }

    else {
        costumer_relationship = level;
    }
}

std::string Person::toString()const{
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

