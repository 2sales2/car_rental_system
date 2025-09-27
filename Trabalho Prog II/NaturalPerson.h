#include <string>

bool verify_cpf(const std::string &aCPF);

class NaturalPerson: public Person {

    friend class RentRegister;
    public:

        // Construtor default
        NaturalPerson(): CPF{"null"},costumer_relationship{-1} {}
        
        // Construtor com parâmetros
        NaturalPerson(std::string name, std::string adress, std::string phone_number, int system_id,
        std::string aCPF, int aRelationship): Person(name,adress,phone_number,system_id) {
            
            // Validando CPF
            if (verify_cpf(aCPF) == true) {
                CPF = aCPF;
            }

            else {
                CPF = "null";
            }

            // Validando nivel de relacionameto
            if (aRelationship < 0 || aRelationship > 5) {
                costumer_relationship = -1;
            }

            else {
                costumer_relationship = aRelationship;
            }
        }

        // Construtor de cópia
        NaturalPerson(const NaturalPerson &person): Person(person),CPF{person.CPF},
        costumer_relationship{person.costumer_relationship} {}

        // Destrutor
        ~NaturalPerson() {}

        // --- Getters ---
        std::string getCPF() {
            return CPF;
        }

        int getRelationship() {
            return costumer_relationship;
        }

        // --- Setters ---
        void setCPF(std::string aCPF) {

            // Validando CPF
            if (verify_cpf(aCPF) == true) {
                CPF = aCPF;
            }

            else {
                CPF = "null";
            }
        }

        void setRelationship(int aRelationship) {

            // Validando nivel de relacionamento
            if (aRelationship < 1 || aRelationship > 5) {
                costumer_relationship = -1;
            }

            else {
                costumer_relationship = aRelationship;
            }

        }

        std::string toString();

    private:
        // Dados-membro
        std::string CPF;
        int costumer_relationship;
        

};

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