#include  "LegalPerson.h"
#include "Person.h"

// --- Getters ---
std::string LegalPerson::getCNPJ() {return CNPJ;}

// --- Setters ---
void LegalPerson::setCNPJ(std::string aCNPJ) {
    // Validando CNPJ
    if (verifyCnpj(aCNPJ) == true) {
        CNPJ = aCNPJ;
    }
    
    else {
        CNPJ = "null";
    }
}

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
        costumer_relationship = newLevel ;
    }
    else
    {
        costumer_relationship = 0 ;
    }
}

std::string LegalPerson::toString(){
    std::string{Person::toString}
}