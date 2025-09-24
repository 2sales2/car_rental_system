#include "Person.h"
#include "Car.h"
#include "Date.h"

int generate_new_RID();

class RentRegister {

    public:
        // Construtor default
        RentRegister(): person{}, car{}, register_id{-1},days{-1},rent_date{},rent_value{0.0} {};

        // Construtor com parâmetros (1)
        RentRegister(Person aperson, Car acar, int ID, int days_with_car,Date date, double rent):
        person{aperson},car{acar},register_id{ID},rent_date{date} {


             // Validando o tempo que o cliente ficou com o carro
            if (days_with_car < 0) {
                days = -1;
            }

            else {
                days = days_with_car;
            }

            // Validando o valor do aluguél
            if (rent < 0) {
                rent_value = 0.0;
            }

            else {
                rent_value = rent;
            }

        }

        // Construtor com parâmetros (2)
        RentRegister(std::string name,
                     std::string adress,
                     std::string phone_number,
                     int system_id,
                     std::string license_plate,
                     int year,
                     std::string model,
                     double km,
                     std::string availability,
                     std::string observations,
                     int R_ID,
                     int days_with_car,
                     int aDay,
                     int aMonth,
                     int aYear,
                     double rent): person{name,adress,phone_number,system_id},
                                   car{license_plate,year,model,km,availability,observations},
                                   register_id{R_ID},
                                   rent_date{aDay,aMonth,aYear} {

            // Validando o tempo que o cliente ficou com o carro
            if (days_with_car < 0) {
                days = -1;
            }

            else {
                days = days_with_car;
            }

            // Validando o valor do aluguél
            if (rent < 0) {
                rent_value = 0.0;
            }

            else {
                rent_value = rent;
            }
    }

        // Construtor de cópia
        RentRegister(const RentRegister &aRegister): person{aRegister.person},car{aRegister.car},
        register_id{aRegister.register_id},days{aRegister.days},rent_date{aRegister.rent_date},
        rent_value{aRegister.rent_value} {}

        // --- Getters ---
        std::string getTenant() {
            
            std::string infos = "Tenant's name: " + person.getName() + "\n" +
                                "Tenant's adress: " + person.getAdress() + "\n" +
                                "Tenant's phone: " + person.getPhone() + "\n" +
                                "Tenant's ID: " + std::to_string(person.getID()) + "\n";

            return infos;
        }

        std::string getRCar() {

            std::string infos = "License plate: " + car.getPlate() + "\n" +
                                "Year: " + std::to_string(car.getYear()) + "\n" +
                                "Model: " + car.getModel() + "\n" +
                                "Km: " + std::to_string(car.getKm()) + "\n" +
                                "Availability: " + car.getAvailability() + "\n" +
                                "Observations: " + car.getObservations() + "\n"; 

            return infos;

        }

        int getRentID() {

            return register_id;
        }

        int getPeriod() {
            return days;
        }

        std::string getRentdate() {
            return rent_date.toString();
        }

        double getRentvalue() {
            return rent_value;
        }

        // --- Setters ---
        void setTenant(std::string name,std::string adress,std::string phone) {
            person.setName(name);
            person.setAdress(adress);
            person.setPhone(phone);
            person.generateID();
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


    private:
        // Dados-membro
        Person person;
        Car car;
        int register_id;
        int days;
        Date rent_date;
        double rent_value;


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