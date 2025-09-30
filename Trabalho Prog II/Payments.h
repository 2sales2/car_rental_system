#ifndef PAYMENTS_H
#define PAYMENTS_H

#include "RentRegister.h"
#include "Person.h"
#include "Car.h"
#include <memory>

class Payments {

    public:
        // Função para calcular acréscimento do valor do carro dado ano
        double calculate_car_acrescimo(int car_year);

        // Função que calcula o desconto do cliente dado um nível de relacionamento
        double calculate_client_discount(int relationship_level);

        // Função que calcula o preço do aluguél
        double calculate_final_rent_value(RentRegister* reg);

};  

#endif