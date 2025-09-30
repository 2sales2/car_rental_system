#ifndef PAYMENTS_H
#define PAYMENTS_H

#include "RentRegister.h"
#include "Person.h"
#include "Car.h"
#include <memory>

class Payments {

    public:
        // Função para calcular acréscimento do valor do carro dado ano
        static double calculate_car_acrescimo(int car_year);

        // Função que calcula o desconto do cliente dado um nível de relacionamento
        static double calculate_client_discount(int relationship_level);

        // Função que calcula o preço do aluguél
        static double calculate_final_rent_value(RentRegister *reg);

        // Processa a devolução e pagamento.
        static std::string process_car_return(RentRegister* reg, double newCarMileage, double amountPaid);
    
        //Permite que o cliente pague dívidas em aberto.
        static std::string process_debt_payment(RentRegister* reg, double amountPaid);

};  

#endif