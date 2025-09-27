#include "LegalPerson.h"
// #include "Person.h"
#include <iostream>

// --- Getters ---
std::string LegalPerson::getCNPJ() {return CNPJ;}

// --- Setters ---

void LegalPerson::setCNPJ(std::string aCNPJ){
    if(verifyCnpj(aCNPJ) == true){
        CNPJ = aCNPJ ;
    }
    else
    {
        CNPJ = "NULL";
    }
}

void LegalPerson::setRelationLevel(int newLevel){
    if(newLevel >= 0 && newLevel <=5){
        custumer_relationship = newLevel ;
    }
    else
    {
        custumer_relationship = 0 ;
    }
}

std::string LegalPerson::toString(){
    std::string output =
        "PESSOA JURIDICA\nNOME : " + name +"\n"+
        "CNPJ : " + CNPJ + "\n" +
        "ENDERECO : " + adress + "\n" +
        "TELEFONE : " + phone_number + "\n" +
        "NIVEL DE RELACIONAMENTO : " + std::to_string(custumer_relationship) + "\n" +
        "ID : " + std::to_string(system_id) + "\n";
    return output ;
}

