#include "Payments.h"


double Payments::calculate_car_acrescimo(int car_year) {

    // Verifica se é carro do ano
    if (car_year == 2025) {
        return 0.50;
    }

    // Verifica se o carro tem até dois anos
    else if (car_year == 2024 || car_year == 2023) {
        return 0.20;
    }

    else {
        0.0;
    }
}


// Função que calcula o desconto do cliente dado um nível de relacionamento
double Payments::calculate_client_discount(int relationship_level) {

    if (relationship_level < 1 || relationship_level > 5) {
        return 0.0;
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

}

// Função que calcula o preço do aluguél
double Payments::calculate_final_rent_value(RentRegister* reg) {

    if (reg == nullptr || reg->person == nullptr || reg->car == nullptr) {
        return 0.0;
    }
}
