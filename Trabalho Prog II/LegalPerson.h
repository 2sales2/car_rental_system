#include "Person.h"
#include <string>

bool verifyCnpj(const std::string &aCNPJ);

class LegalPerson: public Person {
    
    friend class RentRegister;
    public:
        // Construtor default
        LegalPerson(): CNPJ{"null"},custumer_relationship{0} {}

        // Construtor com parâmetros
        LegalPerson(std::string name, std::string adress, std::string phone_number, std::string aCNPJ , int aRelationLevel )
            :Person(name,adress,phone_number){
            
            // Validando CNPJ
            if (verifyCnpj(aCNPJ) == true) {
                CNPJ = aCNPJ;
            }

            else {
                CNPJ = "null";
            }
        
            if(aRelationLevel >= 0 && aRelationLevel <= 5 ){
                custumer_relationship = aRelationLevel;
            }
            else
            {
                custumer_relationship = 0 ; //setado para o nivel mais baixo de relacao
            }
        }

        // Construtor de cópia
        LegalPerson(const LegalPerson &person): Person{person},CNPJ{person.CNPJ}, custumer_relationship{person.custumer_relationship} {}
        
        // --- Getters ---
        std::string getCNPJ();
        int getRelationLevel();

        // --- Setters ---
        void setCNPJ(std::string aCNPJ);
        void setRelationLevel(int newLevel);

        std::string toString();        

        ~LegalPerson() {}

    private:
        // Dados membro
        std::string CNPJ;
        int custumer_relationship ;
};

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