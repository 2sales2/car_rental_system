#include "Agency.h"
#include "Payments.h"
#include "Car.h"
#include "RentRegister.h"
#include "Person.h"
#include "Date.h"
#include "LegalPerson.h"
#include "NaturalPerson.h"
#include "Payments.h"
#include <format>
#include "interfaceScreens.h"

int main() {
    //tela locadora
    Agency agency ;

    Car* carroA = new Car{"ABC1A11", 2020, "Hatch Compacto", 10000, true, "Ar, Direcao", 50.00};
    agency.registerCar(carroA);

    Car* carroB = new Car{"XYZ2B22", 2023, "Sedan Premium", 5000, true, "Completo, GPS", 100.00};
    agency.registerCar(carroB);
    
    Car* carroC = new Car{"CDE3C33", 2022, "SUV", 15000, true, "7 lugares", 80.00};
    agency.registerCar(carroC);

    Person* pessoaA = new NaturalPerson{"Eduardo Fontenele","Rua A","66 996361255","11111111111",1};
    agency.registerCustomer(pessoaA);
    Person* pessoaB = new LegalPerson{"Pedro Sales","Rua B","66 976361133","22222222222222",5};
    agency.registerCustomer(pessoaB);

    Date data_inicio_A{10, 9, 2025}; 
    Date data_retorno_A{15, 9, 2025};
    
    Date data_inicio_B{1, 10, 2025}; 
    Date data_retorno_B{4, 10, 2025};
    
    Date data_inicio_C{25, 10, 2025}; 
    Date data_retorno_C{28, 10, 2025};


    
    while (true) {
        std::cout << std::format("{:=^30}\n"," LOCADORA BATEU & VOLTOU");
        std::cout << "\n1) ALUGAR CARRO.\n" ;
        std::cout << "2) CADASTRAR CARRO.\n" ;
        std::cout << "3) CADASTRAR CLIENTE.\n" ;
        std::cout << "4) REALIZAR PAGAMENTOS.\n" ;
        std::cout << "5) RELATORIOS.\n" ;
        std::cout << "0) SAIR.\n" ;
        int option ;

        std::cout << "\nOPCAO: " ;
        std::cin >> option ;

        // Limpar o buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(option == 1){
            rentCarScreen(agency);
        }

        else if(option == 2){
            registerCarScreen(agency);
        } 

        else if(option == 3){
            registerCustomerScreen(agency);
        }

        else if(option == 4){
            makePaymentScreen(agency);
         }

        else if(option == 5){
            reportsScreen(agency);
        }

        else if (option == 0) {
            std::cout << "Encerrando programa . . .\n";
            break;
        }

        else {
            std::cout << "\nERRO: Opção inválida!\n";
        }
    
    
        
    }
    return 0 ;
}



