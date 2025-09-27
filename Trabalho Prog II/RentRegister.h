#include "Person.h"
#include "Car.h"
#include "Date.h"
#include <string>

int generate_new_RID();

class RentRegister {

    public:
        // Construtor default
        RentRegister(): person{}, car{}, register_id{-1},return_date{},rent_date{},rent_value{0.0},
        in_debt{false},daily_rate{0.0},discount{0.0} {};

        // Construtor com parâmetros
        RentRegister(Person* aperson, Car acar, int ID,Date R_date,Date date, double aRent_value,
        bool debt, double aDaily_rate, double aDiscount):
        person{aperson},car{acar},register_id{ID},return_date{R_date},rent_date{date},in_debt{debt} {

            if (aRent_value < 0) {
                rent_value = 0.0;
            }
            
            else {
                rent_value = aRent_value;
            }

            if (aDaily_rate < 0) {
                daily_rate = 0.0;
            }
            
            else {
                daily_rate = aDaily_rate;
            }


            if (aDiscount< 0) {
                discount = 0.0;
            }
            
            else {
                discount = aDiscount;
            }
        }
       

        int getRentID() {

            return register_id;
        }


        std::string getRentdate() {
            return rent_date.toString();
        }

        double getRentvalue() {
            return rent_value;
        }

        // --- Setters ---
        void setTenant(Person *aPerson){
            
            person = aPerson;
            
        }

        void setRCar(std::string plate,int year,std::string model, double km, std::string availability,std::string observations) {

            car.setPlate(plate);
            car.setYear(year);
            car.setModel(model);
            car.setKm(km);
            car.setAvailability(availability);
            car.setObservations(observations);

        }

        void generatetRID() {
            register_id = generate_new_RID();
        }

        void setRentdate(int day,int month,int year) {

            rent_date.setDM(day,month);
            rent_date.setYear(year);

        }

        void setRentvalue(double value) {

            if (value < 0) {
                rent_value = 0.0;
            }

            else {
                rent_value = value;
            }

        }

        std::string toString();





    private:
        // Dados-membro
        Person* person;
        Car car;
        int register_id;
        Date return_date;
        Date rent_date;
        double rent_value; // valor do aluguél
        bool in_debt = false; // booleano para identificar se o cliente está endividado
        double daily_rate; // valor da diária
        double discount; // valor do desconto

};

int generate_new_RID() {

    // Códigos de registros terão prefixo 2 no inicio de cada ID
    std::string new_id{"2"};

    std::random_device seed{};
    std::default_random_engine engine{seed()};
    std::uniform_int_distribution generator{1000,9999};

    int ID = generator(engine);

    new_id += std::to_string(ID);

    return std::stoi(new_id);

}