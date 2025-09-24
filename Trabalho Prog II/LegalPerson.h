
bool verify_cnpj(const std::string &aCNPJ);

class LegalPerson: public Person {
    
    friend class RentRegister;
    public:
        // Construtor default
        LegalPerson(): CNPJ{"null"} {}

        // Construtor com parâmetros
        LegalPerson(std::string name, std::string adress, std::string phone_number,int system_id, std::string aCNPJ):
        Person(name,adress,phone_number,system_id){
            
            // Validando CNPJ
            if (verify_cnpj(aCNPJ) == true) {
                CNPJ = aCNPJ;
            }

            else {
                CNPJ = "null";
            }
        }

        // Construtor de cópia
        LegalPerson(const LegalPerson &person): Person{person},CNPJ{person.CNPJ} {}

        // Destrutor
        ~LegalPerson() {}

        // --- Getters ---
        std::string getCNPJ() {
            return CNPJ;
        }

        // --- Setters ---
        void setCNPJ(std::string aCNPJ) {

            // Validando CNPJ
            if (verify_cnpj(aCNPJ) == true) {
                CNPJ = aCNPJ;
            }

            else {
                CNPJ = "null";
            }
        }

    private:
        // Dados membro
        std::string CNPJ;

};

bool verify_cnpj(const std::string &aCNPJ) {

    int number_of_digits{0};

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