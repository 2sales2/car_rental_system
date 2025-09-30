#ifndef LEGAL_PERSON_H
#define LEGAL_PERSON_H

#include "Person.h"
#include <string>

bool verifyCnpj(const std::string &aCNPJ);

class LegalPerson: public Person {
    
    friend class RentRegister;
    public:
        // Construtor default
        LegalPerson(): CNPJ{"null"} {}

        // Construtor com parâmetros
        LegalPerson(std::string name, std::string adress, std::string phone_number, std::string aCNPJ , int aRelationLevel )
                   :Person(name,adress,phone_number,aRelationLevel) {
            
            // Validando CNPJ
            if (verifyCnpj(aCNPJ) == true) {
                CNPJ = aCNPJ;
            }

            else {
                CNPJ = "null";
            }
        
        }

        // Construtor de cópia
        LegalPerson(const LegalPerson &person): Person{person},CNPJ{person.CNPJ} {}
        
        // --- Getters ---
        std::string getCNPJ();

        // --- Setters ---
        void setCNPJ(std::string aCNPJ);

        std::string toString();        

        ~LegalPerson() {}

    private:
        // Dados membro
        std::string CNPJ;
};


#endif