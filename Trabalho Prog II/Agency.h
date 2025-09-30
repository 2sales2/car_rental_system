#ifndef AGENCY_H
#define AGENCY_H


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "LegalPerson.h"
#include "NaturalPerson.h"
#include "Person.h"
#include "Car.h"
#include "RentRegister.h"


class Agency {
    public:

        // Função para adicionar carro no vector
        void registerCar(const Car &newCar);

        // Função para adicionar pessoa no vector
        void registerClient(std::shared_ptr<Person> newClient);
        
        Car* get_car_by_plate(std::string plate);
        Car* get_car_by_model(std::string model);
        
        std::string reportCarsRented(Date startPeriod , Date endPeriod);
        RentRegister* get_register_by_id(int id);

    private:
       
        std::vector<Car> carsList {} ;
        std::vector<std::shared_ptr<Person>> clients {};
        std::vector<RentRegister*> registerList {};
};

#endif