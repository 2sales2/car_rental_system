#include "Agency.h"

//adiciona carro a lista / adicionarno arquivo
void Agency::registerCar(const Car newCar){
    carsList.push_back(newCar);
}

std::vector<Car> Agency::getCarsList(){
    return carsList ;
}

std::string Agency::reportCarsRented(Date startPeriod , Date endPeriod){
    
    std::string output {"----- RELATORIO DE CARROS ALUGADOS -----\n\n"} ;
    

    for(RentRegister reg : registerList){
        
    }
}
