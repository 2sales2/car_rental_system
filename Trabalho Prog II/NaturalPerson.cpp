#include "Person.h"
#include "NaturalPerson.h"
#include <iostream>

// ---- Getters ----
std::string NaturalPerson::getCPF() {
    return CPF;
}

int NaturalPerson::getRelationship() {
    return costumer_relationship;
}


//--- Setters ---
void NaturalPerson::setCPF(std::string aCPF) {
    
    bool correct_cpf = verify_cpf(aCPF);

    if (correct_cpf) {
        CPF = aCPF;
    }

    else {
        CPF = "null";
    }
}

void NaturalPerson::setRelationship(int aRelationship) {
    if (aRelationship < 0 || aRelationship > 5) {
        costumer_relationship = 0;
    }

    else {
        costumer_relationship = aRelationship;
    }
}


std::string NaturalPerson::toString(){

    std::string output = 
        
        "PESSOA FISICA \nNOME : " + name + "\n" +
        "ENDERECO : " + adress + "\n" +
        "TELEFONE : " + phone_number + "\n" +
        "CPF: " + CPF + "\n" + 
        "NÍVEL DE RELACIONAMENTO: " + std::to_string(costumer_relationship) + "\n" +
        "ID : " + std::to_string(system_id) + "\n" ;        

    return output;
}

bool verify_cpf(const std::string &aCPF) {

    int number_of_digits{0};

    // Validando CPF
    if (aCPF.length() < 11 || aCPF.length() > 11) {
        return false;
    }

    else {

        for(int i{0}; i < 11; i++) {

            if(std::isdigit(aCPF.at(i))) {
                number_of_digits++;
            }
        }

        if (number_of_digits == 11) {
            return true;
        }

        else {        
            return false;
        }
    }

    return false;
}
