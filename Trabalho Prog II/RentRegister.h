#ifndef RENT_REGISTER_H
#define RENT_REGISTER_H

#include "Person.h"
#include "Car.h"
#include "Date.h"
#include <string>

int generate_new_RID();


class RentRegister {

    friend class Payments;
    
    public:
        // Construtor default
        RentRegister(): person{}, car{}, register_id{generate_new_RID()},return_date{},rent_date{},rent_value{0.0},
        paid{false},daily_rate{0.0},discount{0.0} {};

        // Construtor com parâmetros
        RentRegister(Person* aperson, Car aCar,Date R_date,Date date, double aRent_value,
        bool debt, double aDaily_rate, double aDiscount):
        person{aperson},car{&aCar},register_id{generate_new_RID()},return_date{R_date},rent_date{date},paid{debt} {

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
       
        // --- Getters ---
        Person* getTenant();
        Car* getRentedCar();
        int getRegisterID();
        Date getReturnDate();
        Date getRentDate();
        double getRentValue();
        bool isPaid(); // Mudei o nome da função (dudu)
        double getDailyRate();
        double getDiscount();

        // --- Setters ---
        void registerTenant(Person *aPerson);
        void registerCar(Car aCar);
        void registerRentDate(Date aDate);
        void registerRentValue(double value);
        void registerReturnDate(Date aDate);
        void registerValue(double value);
        void registerDailyRate(double aDaily_rate);
        void registerDiscount(double aDiscount);

        // Método para visualizar os dados do registro
        std::string toString();

        // Método para calcular a diária
        double calculate_rentValue();

    private:
        // Dados-membro
        Person* person;
        Car* car; 

        int register_id;

        Date return_date;
        Date rent_date;

        bool paid = false; // booleano para identificar se o cliente está endividado

        double rent_value; // valor do aluguél
        double daily_rate; // valor da diária
        double discount; // valor do desconto
        double total_debt;

};

#endif
