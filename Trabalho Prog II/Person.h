#include <iostream>
#include <string>
#include <random>

int generate_new_ID();

class Person {

    friend class RentRegister;
    public:

        // Construtor default
        Person(): name{"null"},adress{"null"},phone_number{"null"},system_id{-1} {}

        // Construtor com parâmetros
        Person(std::string aName, std::string anAdress, std::string aPhoneNumber, int anID):
        name{aName},adress{anAdress},phone_number{aPhoneNumber},system_id{anID} {}

        // Construtor de cópia
        Person(const Person &aPerson): name{aPerson.name},adress{aPerson.adress},
        phone_number{aPerson.phone_number}, system_id{aPerson.system_id} {}

        // Destrutor
        ~Person() {}

        // --- Getters ---
        std::string getName() {
            return name;
        }

        std::string getAdress() {
            return adress;
        }

        std::string getPhone() {
            return phone_number;
        }

        int getID() {
            return system_id;
        }

        //--- Setters ---
        void setName(std::string aName) {
            name = aName;
        }

        void setAdress(std::string anAdress) {
            adress = anAdress;
        }

        void setPhone(std::string aPhone) {
            phone_number = aPhone;
        }

        void generateID() {
            system_id = generate_new_ID();

        }

        virtual std::string toString();

    private:
    // Dados-membro
        std::string name;
        std::string adress;
        std::string phone_number;
        int system_id;

};

int generate_new_ID() {

    // Códigos de clientes terão prefixo 1 no inicio de cada ID
    std::string new_id{"1"};

    std::random_device seed{};
    std::default_random_engine engine{seed()};
    std::uniform_int_distribution generator{1000,9999};

    int ID = generator(engine);

    new_id += std::to_string(ID);

    return std::stoi(new_id);

}