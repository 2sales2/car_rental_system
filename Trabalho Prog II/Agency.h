#ifndef AGENCY_H
#define AGENCY_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "LegalPerson.h"
#include "NaturalPerson.h"
#include "Person.h"
#include "Car.h"
#include "RentRegister.h"

#define CLIENTS_FILE "customers.txt"
#define CARS_FILE "cars.txt"
#define REGISTERS_FILE "registers.txt"

class Agency {
    public:

        void registerCar(Car *newCar);
        void registerCustomer(Person *newCustomer);    
        void registerReg(RentRegister *newReg);

        Car* getCarByPlate(const std::string plate);
        Car* getCarByModel(const std::string model);
        RentRegister* getRegisterById(const int id);
        Person* getCustomer(const std::string document);
        bool hasPendingDebt(Person* customer);

        std::string reportCarsRented(const Date startPeriod , const Date endPeriod);
        std::string billingReport(const Date startPeriod , const Date endPeriod);
        std::string listCars(bool available = false);
        std::string reportIndebtCustomers();
        std::string reportCustomerInf(const std::string document);

    private:
       
        std::vector<Car*> carsList {} ;
        std::vector<Person*> customers {};
        std::vector<RentRegister*> registerList {};
};


#endif