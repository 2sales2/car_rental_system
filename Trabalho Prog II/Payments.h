#ifndef PAYMENTS_H
#define PAYMENTS_H

class RentRegister; 
#include "Person.h"
#include "Car.h"


class Payments {

    public:
        // Função para calcular acréscimento do valor do carro dado ano
        static double calculate_car_acrescimo(int car_year);

        // Função que calcula o desconto do cliente dado um nível de relacionamento
        static double calculate_client_discount(int relationship_level);

       
        // Processa a devolução
        static bool process_car_return(RentRegister* reg, int newKm);

        // Processa pagamento.
        static std::string process_payment(RentRegister* reg, double newCarMileage, double amountPaid, int new_km);
    
        //Função que permite que o cliente pague dívidas em aberto.
        static std::string process_debt_payment(RentRegister* reg, double amountPaid);

        // Função que verifica se o cliente pode alugar um carro
        static bool can_rent(RentRegister* reg);

};  

#endif