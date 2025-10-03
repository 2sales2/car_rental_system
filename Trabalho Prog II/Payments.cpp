#include "Payments.h"
#include <cmath>
#include <string>

double Payments::calculate_car_acrescimo(int car_year) {

    // Verifica se é carro do ano
    if (car_year == 2025) {
        return 0.50;
    }

    // Verifica se o carro tem até dois anos
    else if (car_year == 2024 || car_year == 2023) {
        return 0.20;
    }

    return 0.0;
}


// Função que calcula o desconto do cliente dado um nível de relacionamento
double Payments::calculate_client_discount(int relationship_level) {

    if (relationship_level < 1 || relationship_level > 5) {
        0.0;
    }

    else if (relationship_level == 1) {
        return 0.02;
    }

    else if (relationship_level == 2) {
       return 0.035;
    }

    else if (relationship_level == 3) {
        return 0.04;
    }

    else if (relationship_level == 4) {
        return 0.06;
    }

    else {
        return 0.08;
    }

    return 0.0;
}

// Função que calcula o preço do aluguél

bool Payments::process_car_return(RentRegister* reg,int new_km) {


    Car* car = reg->getRentedCar();

    // Atualiza a kilometragem do carro
    if (car != nullptr) {

        car->updateKM(new_km);
        car->setAvailability(true); 

        return true;
    }

    return false;
}

std::string Payments::process_payment(RentRegister* reg, double amountPaid, int new_km) {

    std::string receipt;
    double final_value = reg->calculate_rentValue();
    bool returned = process_car_return(reg,new_km);


    if (returned) {

        if (amountPaid >= final_value) {
            // Pagamento completo ou maior
            reg->setPaidStatus(true);
            reg->setTotalDebt(0.0);

            // Calculo do troco
            double change = amountPaid - final_value;

            // emissão do recibo
            receipt = " RECIBO DE ALUGUEL E DEVOLUÇÃO \n" + 
                  reg->toString() +
                  "VALOR TOTAL DO ALUGUEL: R$ " + std::to_string(final_value) + "\n" +
                  "VALOR PAGO: R$ " + std::to_string(amountPaid) + "\n" +
                  "TROCO: R$ " + std::to_string(change) + "\n" +
                  "SITUAÇÃO: PAGO \n";

            if (change > 0.01) {
                receipt += "TROCO DE R$ " + std::to_string(change) + " ENTREGUE AO CLIENTE.\n";
            }

        }
    
        else {

            // Pagamento parcial ou nenhum
            double debt = final_value - amountPaid;
            reg->setPaidStatus(false);
            reg->setTotalDebt(debt);


            receipt = "REGISTRO DE DÍVIDA \n" +
                    reg->toString() +
                    "VALOR TOTAL DO ALUGUEL: R$ " + std::to_string(final_value) + "\n" +
                    "VALOR PAGO: R$ " + std::to_string(amountPaid) + "\n" +
                    "VALOR FALTANTE: R$ " + std::to_string(debt) + "\n" +
                    "SITUAÇÃO: DÍVIDA PENDENTE \n";
                   
        }

    }

    return receipt;
   
}

std::string Payments::process_debt_payment(RentRegister* reg, double amountPaid) {

    double current_debt = reg->total_debt;
    std::string receipt;

    // Verifica se há dívida pendente
    if (current_debt <= 0.0) {
        return "Nenhuma dívida pendente.";
    }

    if (amountPaid >= current_debt) {
        reg->setPaidStatus(true);
        reg->setTotalDebt(0.0);

        // Calculo do troco
        double change = amountPaid - current_debt;

        receipt = " RECIBO DE PAGAMENTO DE DÍVIDA \n" +
                  reg->toString() +
                  "VALOR DA DÍVIDA: R$ " + std::to_string(current_debt) + "\n" +
                  "VALOR PAGO: R$ " + std::to_string(amountPaid) + "\n" +
                  "SITUAÇÃO: DÍVIDA PAGA \n";

        // verifica troca  
        if (change > 0.01) {
            receipt += "TROCO: R$" + std::to_string(change) + " ENTREGUE AO CLIENTE.\n";
        }

    }

    else {

        // Calculo do valor restante da dívida
        double remaining_debt = current_debt - amountPaid;
        reg->setTotalDebt(remaining_debt);

        receipt = " RECIBO DE PAGAMENTO PARCIAL DE DÍVIDA \n" +
                  reg->toString() +
                  "VALOR PAGO: R$ " + std::to_string(amountPaid) + "\n" +
                  "VALOR RESTANTE DA DÍVIDA: R$ " + std::to_string(remaining_debt) + "\n";

    }

    return receipt;

}

bool Payments::can_rent(RentRegister* reg) {

    if (reg->person == nullptr) {
        return false;
    }

    // Verifica se o cliente tem dívidas pendentes
    if (reg->isPaid() == false && reg->total_debt > 0.0) {
        return false;
    }

    return true;
}