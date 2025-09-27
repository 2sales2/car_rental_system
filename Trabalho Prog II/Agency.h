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
        
        void registerClient(Person* new_client);
        std::string reportCarsRented(Date startPeriod , Date endPeriod);
        Car get_car_by_plate(std::string plate);
        Car get_car_by_model(std::string model);
        
        private:
        Car currentCar ;
        Person* currentPerson ;
        std::vector<Car> carsList {} ;
        std::vector<Person*> clients {};
        std::vector<RentRegister> registerList {};
};