#ifndef NATURAL_PERSON_H
#define NATURAL_PERSON_H

#include <string>

bool verify_cpf(const std::string &aCPF);

class NaturalPerson: public Person {

    friend class RentRegister;
    public:

        // Construtor default
        NaturalPerson(): CPF{"null"} {}
        
        // Construtor com parâmetros
        NaturalPerson(std::string aName, std::string adress, std::string phone_number,
        std::string aCPF, int aRelationship):
         Person(aName,adress,phone_number,aRelationship) {
            
            // Validando CPF
            if (verify_cpf(aCPF) == true) {
                CPF = aCPF;
            }

            else {
                CPF = "null";
            }
        }

        // Construtor de cópia
        NaturalPerson(const NaturalPerson &person): Person(person),CPF{person.CPF} {}

        // Destrutor
        ~NaturalPerson() {}

        // --- Getters ---
        std::string getCPF();
        
        // --- Setters ---
        void setCPF(std::string aCPF);
        
        std::string toString();
        
    private:
        // Dados-membro
        std::string CPF;

};

#endif