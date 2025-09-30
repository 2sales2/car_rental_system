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

void Car::setAvailability(bool anAvailability) {
    availability = anAvailability;
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

void Car::updateKM(int new_km) {

    if (new_km > km) {
        km = new_km;
    }
}



//  0  1  2  3  4  5   6
// "L  L  L  N  L  N  N"
bool verify_license_plate(const std::string &aPlate) {

    // Validando a quantidade de digitos de uma placa levando em consideração o novo padrão do Merco-Sul
    if(aPlate.length() != 7) {
        return false;
    }

    else {

        // Verificação de digitos de uma placa levando em conta o novo padrão do Merco-Sul
        for (int i{0}; i < 7; i++) {

            // Verifica os 3 primeiros digitos
            if(i < 3) {

                if (!std::isalpha(aPlate.at(i))) {
                    return false;

                }
            }
            
            // Verifica o quarto digito
            if (i == 3) {
                if (!std::isdigit(aPlate.at(i))) {
                    return false;
                }
            }

            // Verifica o quinto digito
            if (i == 4) {
                if (!std::isalpha(aPlate.at(i))) {
                    return false;
                }
            }
            
            // Verifica os dois ultimos digitos
            if(i > 4) {

                if(!std::isdigit(aPlate.at(i))) {
                    return false;
                }

            }

        } 
    }

    return true;
    
}