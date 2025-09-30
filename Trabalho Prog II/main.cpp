#include "Agency.h"
#include "Payments.h"
#include "Car.h"
#include "RentRegister.h"
#include "Person.h"


int main() {


    Person* client = new LegalPerson("Empresa Teste SA", "Rua A, 100", "55554444", "12345678000199", 3);
    Car* carro = new Car {"ABC1D23", 2023, "Modelo X", 15000, true, "Nenhuma", 200.0};

    Date data_aluguel(15, 10, 2024);
    Date data_devolucao(20, 10, 2024);

    RentRegister* registro = new RentRegister();

    registro->registerTenant(client);
    registro->registerCar(carro);
    registro->registerRentDate(data_aluguel);
    registro->registerReturnDate(data_devolucao);
    registro->registerDailyRate(carro->getPrice());

    double a = Payments::calculate_final_rent_value(registro);
    double d = Payments::calculate_client_discount(client->getRelationship());

    registro->registerValue(a);
    registro->registerDiscount(d);

    // Calcula a diferença de dias (Para referência)
    long diff = Date::days_diferrence(data_devolucao, data_aluguel);

    // 4. SAÍDA DE DADOS
    std::cout << "\n--- TESTE DE PAGAMENTO ---\n";
    std::cout << registro->toString() << std::endl;
    std::cout << "Período Alugado: " << std::abs(diff) << " dias" << std::endl;
    std::cout << "---------------------------------\n";

    // 5. LIMPEZA DE MEMÓRIA
    delete carro; 
    
    return 0;
}



