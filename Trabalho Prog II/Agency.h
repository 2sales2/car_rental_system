#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Person.h"
#include "Car.h"
#include "RentRegister.h"


class Agency {
    public:
                
        void registerCar(const Car &newCar);
        void registerClient(std::shared_ptr<Person> newClient);
        
        Car* get_car_by_plate(std::string plate);
        Car* get_car_by_model(std::string model);
        
        std::string reportCarsRented(Date startPeriod , Date endPeriod);

        private:
       
        std::vector<Car> carsList {} ;
        std::vector<std::shared_ptr<Person>> clients {};
        std::vector<RentRegister*> registerList {};
};