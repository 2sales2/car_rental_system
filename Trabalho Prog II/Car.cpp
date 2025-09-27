#include "Car.h"
#include <iostream>

//GETTERS
std::string Car::getPlate() {return license_plate;}
int Car::getYear() {return year;}
std::string Car::getModel() {return model;}
int Car::getKm() {return km;}
bool Car::getAvailability() {return availability;}
std::string Car::getObservations() {return observations;}
double Car::getPrice() { return price;}

//SETTERS
void Car::setPlate(const std::string &aPlate) {

    if (verify_license_plate(aPlate) == true) {
        license_plate = aPlate;
        }

    else
    {
        license_plate = "LLLNLNN";
    }
}

void Car::setYear(int aYear) {
    if (aYear < 1886) {
        year = -1;
    }
    else{
        year = aYear;
    }
}

void Car::setModel(std::string aModel) {
    model = aModel;
}

void Car::setKm(int aKm) {
    // Validando quilometragem
    if (aKm < 0) {
        km = -1;
    }
    else {
        km = aKm;
    }
}

void Car::setObservations(std::string anObservation) {
    observations = anObservation;
}

void Car::setPrice(double aPrice) {
    
    if (aPrice < 0.0) {
        price = 0.0;
    }

    else {
        price = aPrice;
    }
}

std::string Car::toString(){
    std::string output =
    "MODELO : " + model + "\n"+
    "ANO : " + std::to_string(year) + "\n"+
    "QUILOMETRAGEM : " + std::to_string(km) + "\n" +
    "PLACA : " + license_plate + "\n";
    
    if(availability == true){
        output.append("DISPONIBILIDADE : DISPONIVEL \n");
    }
    else
    {
        output.append("DISPONIBILIDADE : INDISPONIVEL \n");
    }

    return output ;
}

