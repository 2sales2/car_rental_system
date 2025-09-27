#include <string>

bool verify_cpf(const std::string &aCPF);

class NaturalPerson: public Person {

    friend class RentRegister;
    public:

        // Construtor default
        NaturalPerson(): CPF{"null"},costumer_relationship{-1} {}
        
        // Construtor com parâmetros
        NaturalPerson(std::string aName, std::string adress, std::string phone_number,
        std::string aCPF, int aRelationship):
         Person(aName,adress,phone_number) {
            
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
        std::string getCPF();

        int getRelationship();
        
        // --- Setters ---
        void setCPF(std::string aCPF);
        
        void setRelationship(int aRelationship);
        
        std::string toString();
        
    private:
        // Dados-membro
        std::string CPF;
        int costumer_relationship;
        

};
