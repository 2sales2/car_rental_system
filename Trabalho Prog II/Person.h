#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <random>

int generate_new_ID();

class Person {

    friend class RentRegister;
    public:

        // Construtor default
        Person(): name{"null"},adress{"null"},phone_number{"null"},system_id{generate_new_ID()},costumer_relationship{0}{}

        // Construtor com parâmetros
        Person(std::string aName, std::string anAdress, std::string aPhoneNumber, int level):
        name{aName},adress{anAdress},phone_number{aPhoneNumber},system_id{generate_new_ID()} {

            // Validando nível de relacionamento
            if (level < 0 || level > 5) {
                costumer_relationship = 0;
            }

            else {
                costumer_relationship = level;
            }
        }

        // Construtor de cópia
        Person(const Person &aPerson): name{aPerson.name},adress{aPerson.adress},
        phone_number{aPerson.phone_number}, system_id{aPerson.system_id}, costumer_relationship{aPerson.costumer_relationship} {}
        
        // --- Getters ---
        std::string getName();
        std::string getAdress();
        std::string getPhone();
        int getID();
        int getRelationship();
        
        // Destrutor
        virtual ~Person() = default;
        
        //--- Setters ---
        void setName(std::string aName);
        void setAdress(std::string anAdress);
        void setPhone(std::string aPhone);
        void generateID();
        void setRelationship(int level);

        virtual std::string toString();

    protected:
    // Dados-membro
        std::string name;
        std::string adress;
        std::string phone_number;
        int system_id;
        int costumer_relationship;

};

#endif