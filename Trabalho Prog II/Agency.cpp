#include "Agency.h"

//adiciona carro a lista / adicionarno arquivo
void Agency::registerCar(const Car newCar){
    carsList.push_back(newCar);
}

std::vector<Car> Agency::getCarsList(){
    return carsList ;
}
