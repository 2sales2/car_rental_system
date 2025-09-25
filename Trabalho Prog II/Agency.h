#include <iostream>
#include <string>
#include <vector>
// #include "Person.h"
#include "Car.h"
// #include "RentRegister.h"

class Agency {
    public:

        void registerCar(Car newCar);
        std::vector<Car> getCarsList();

    private:

        std::vector<Car> carsList {} ;

};