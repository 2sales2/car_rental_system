#include "RentRegister.h"
#include <iostream>

// -- GETTERS ---
Person* RentRegister::getTenant() {return person;}

Car RentRegister::getRentedCar() {return car;}

int RentRegister::getRegisterID() {return register_id;}

std::string RentRegister::getReturnDate() {return return_date.toString();}

std::string RentRegister::getRentDate() {return rent_date.toString();}

double RentRegister::getRentValue() {return rent_value;}

bool RentRegister::getSituation(){return in_debt;}

double RentRegister::getDailyRate() {return daily_rate;}

double RentRegister::getDiscount() {return discount;}

// -- SETTERS ---
void RentRegister::registerTenant(Person* aPerson) {

    if (aPerson == nullptr) {
        person = nullptr;
    }

    else {
        person = aPerson;
    }

}

void RentRegister::registerCar(Car aCar) {car = aCar;}

void RentRegister::registerRentDate(Date aDate) {rent_date = aDate;}


void RentRegister::registerRentValue(double value) {

    if (value < 0.0) {
        rent_value = 0.0;
    }

    else {
        rent_value = value;
    }
}

void RentRegister::registerReturnDate(Date aDate) {return_date = aDate;}

void RentRegister::registerValue(double aValue) {rent_value = aValue;}

void RentRegister::registerDebt(bool situation) {in_debt = situation;}

void RentRegister::registerDailyRate(double aDaily_rate) {daily_rate = aDaily_rate;}

void RentRegister::registerDiscount(double aDiscount) {discount = aDiscount;}

int generate_new_RID() {

    // Códigos de registros terão prefixo 2 no inicio de cada ID
    std::string new_id{"2"};

    std::random_device seed{};
    std::default_random_engine engine{seed()};
    std::uniform_int_distribution generator{1000,9999};

    int ID = generator(engine);

    new_id += std::to_string(ID);

    return std::stoi(new_id);

}


std::string RentRegister::toString(){
    std::string output = "DADOS DO LOCATÁRIO:\n" + 
                          person->toString()+
                          "\nDADOS DO CARRO ALUGADO:\n" +
                          car.toString() + 
                          "\nCONTRATO:\n" +
                          "ID DO REGISTRO: " + std::to_string(register_id) + "\n" +
                          "DATA DO ALUGUÉL: " + rent_date.toString() + "\n" +
                          "DATA DE DEVOLUÇÃO:" + return_date.toString() + "\n" +
                          "VALOR DO ALUGÚEL: " +  "R$" + std::to_string(rent_value) + "\n" +
                          "VALOR DA DIÁRIA: " + "R$" + std::to_string(daily_rate) + "\n" +
                          "STATUS DO PAGAMENTO:" +  std::to_string(car.availability) + "\n" +
                          "VALOR DO DESCONTO: " + "R$" + std::to_string(discount) + "\n";
        
    return output;
}
