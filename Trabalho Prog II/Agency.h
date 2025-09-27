#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Car.h"
#include "RentRegister.h"


class Agency {
    public:
        void registerCar(const Car newCar);
        std::vector<Car> getCarsList();
        

        std::string reportCarsRented(Date startPeriod , Date endPeriod);


        private:
        Car currentCar ;
        Person* currentPerson ;
        std::vector<Car> carsList {} ;
        std::vector<Person*> clientList {};
        std::vector<RentRegister> registerList {};
};