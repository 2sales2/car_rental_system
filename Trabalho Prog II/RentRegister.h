#ifndef RENT_REGISTER_H
#define RENT_REGISTER_H

class Car;
#include "Car.h"
#include "Person.h"
#include "Date.h"
#include <string>
#include "Payments.h"




class RentRegister {

    friend class Payments;
    
    public:
        // Construtor default
        RentRegister(): person{nullptr}, car{nullptr}, register_id{count++},return_date{},rent_date{},rent_value{0.0},
        paid{false},daily_rate{0.0},discount{0.0},total_debt{0.0} {};

        // Construtor com parâmetros
        RentRegister(Person* aperson, Car *aCar , Date R_date,Date date,
        double dailyValue ,bool debt):
        person{aperson},car{aCar},register_id{count++},return_date{R_date},rent_date{date},paid{debt},rent_value{calculate_rentValue()} ,
        daily_rate{dailyValue},discount{} {
                        
        }
       
        // --- Getters ---
        Person* getTenant()const;
        Car* getRentedCar()const;
        int getRegisterID()const;
        Date getReturnDate()const;
        const Date& getRentDate()const;
        double getRentValue()const;
        bool isPaid()const; // Mudei o nome da função (dudu)
        double getDailyRate()const;
        double getDiscount()const;
        double getTotalDebt()const;

        // --- Setters ---
        void registerTenant(Person *aPerson);
        void registerCar(Car* aCar);
        void registerRentDate(Date aDate);
        void registerRentValue(double value);
        void registerReturnDate(Date aDate);
        void registerValue(double value);
        void registerDailyRate(double aDaily_rate);
        void registerDiscount(double aDiscount);
        void setPaidStatus(bool situation);
        void setTotalDebt(double aDebt);

        // Método para visualizar os dados do registro
        std::string toString();

        // Método para calcular a diária
        double calculate_rentValue();

    private:
        // Dados-membro
        Person* person;
        Car* car;

        static int count ;
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
