#include "RentRegister.h"
#include <iostream>
int RentRegister::count = 1  ;
// -- GETTERS ---
Person* RentRegister::getTenant()const {return person;}

Car* RentRegister::getRentedCar()const {return car;}

int RentRegister::getRegisterID()const {return register_id;}

Date RentRegister::getReturnDate()const {return return_date;}

const Date &RentRegister::getRentDate()const {return rent_date;}

double RentRegister::getRentValue()const {return rent_value;}

bool RentRegister::isPaid()const {return paid;}

double RentRegister::getDailyRate()const {return daily_rate;}

double RentRegister::getDiscount()const {return discount;}

double RentRegister::getTotalDebt()const {return total_debt;}

// -- SETTERS ---
void RentRegister::registerTenant(Person* aPerson) {

    if (aPerson == nullptr) {
        person = nullptr;
    }

    else {
        person = aPerson;
    }

}

void RentRegister::registerCar(Car* aCar) {car = aCar;}

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

void RentRegister::registerDailyRate(double aDaily_rate) {daily_rate = aDaily_rate;}

void RentRegister::registerDiscount(double aDiscount) {discount = aDiscount;}

void RentRegister::setPaidStatus(bool situation) {paid = situation;}

void RentRegister::setTotalDebt(double aDebt) {
    
    if (aDebt < 0.0) {
        total_debt = 0.0;
    }

    else {
        total_debt = aDebt;
    }
}


std::string RentRegister::toString(){


    std::string output = "DADOS DO LOCATÁRIO:\n" + 
                          person->toString()+
                          "\nDADOS DO CARRO ALUGADO:\n" +
                          car->toString() + 
                          "\nCONTRATO:\n" +
                          "ID DO REGISTRO: " + std::to_string(register_id) + "\n" +
                          "DATA DO ALUGUÉL: " + rent_date.toString() + "\n" +
                          "DATA DE DEVOLUÇÃO:" + return_date.toString() + "\n" +
                          "VALOR DO ALUGÚEL: " +  "R$" + std::to_string(rent_value) + "\n" +
                          "VALOR DA DIÁRIA: " + "R$" + std::to_string(daily_rate) + "\n" +
                          "VALOR DO DESCONTO: " + "R$" + std::to_string(discount) + "\n";
        
    return output;
}

double RentRegister::calculate_rentValue(){

    
    // Retorna a diferença em dias da data do aluguél do carro e da data de devolução
    long days_diff = Date::days_diferrence(return_date,rent_date);

    // converte para inteiro 
    int rent_days = static_cast<int>(std::abs(days_diff));

    double base_daily_rate = daily_rate;

    // cálculo do acréscimo do valor do carro
    double car_acrescimo = Payments::calculate_car_acrescimo(car->getYear());

    double value_with_acrescimo = base_daily_rate * (1.0 + car_acrescimo);

    // Calcula o valor do desconto
    double discount_rate = Payments::calculate_client_discount(person->getRelationship());

    // Aplicação do Desconto
    double finalDailyValue = value_with_acrescimo * (1.0 - discount_rate);

    // Valor Total (Diária Final * Dias de Aluguel)
    double finalValue = finalDailyValue * rent_days;
    return finalValue;
    
}



