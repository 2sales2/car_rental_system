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
    

    while (true)
    {
        std::cout << std::format("{:-^30}\n","LOCADORA SALES");
        std::cout << "1) ALUGAR CARRO :\n" ;
        std::cout << "2) CADASTRAR CARRO :\n" ;
        std::cout << "3) CADASTRAR CLIENTE :\n" ;
        std::cout << "4) REALIZAR PAGAMENTOS :\n" ;
        std::cout << "5) RELATORIOS :\n" ;
        std::cout << "0) SAIR :\n" ;
        int option ;
        std::cout << "\nOPCAO : \n" ;
        std::cin >> option ;
        
        if(option == 1){
            rentCarScreen(agency);
    //     }

    //     if(option == 2){
    //         registerCarScreen();
    //     }

    //     if(option == 3){
    //         registerCustomerScreen();
    //     }

    //     if(option == 4){
    //         makePaymentScreen();
    //     }

    //     if(option == 5){
    //         reportsScreen();
    //     }
    }
    
    return 0 ;

    }
}



