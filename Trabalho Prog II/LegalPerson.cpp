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


std::string LegalPerson::toString(){
    std::string output =
        "PESSOA JURIDICA\nNOME : " + name +"\n"+
        "CNPJ : " + CNPJ + "\n" +
        "ENDERECO : " + adress + "\n" +
        "TELEFONE : " + phone_number + "\n" +
        "NIVEL DE RELACIONAMENTO : " + std::to_string(costumer_relationship) + "\n" +
        "ID : " + std::to_string(system_id) + "\n";
    return output ;
}

bool verifyCnpj(const std::string &aCNPJ) {

    int number_of_digits{0};
    int custumer_relationship ;
    // Validando CPF
    if (aCNPJ.length() < 14 || aCNPJ.length() > 14) {
        return false;
    }

    else {

        for(int i{0}; i < 14; i++) {

            if(std::isdigit(aCNPJ.at(i))) {
                number_of_digits++;
            }
        }

        if (number_of_digits == 14) {
            return true;
        }

        else {        
            return false;
        }
    }

    return false;
}

