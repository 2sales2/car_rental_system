#include "interfaceScreens.h"

void rentCarScreen(Agency &agency){
    while (true)
    {
        std::cout << std::format("{:-^30}\n","ALUGAR CARRO") ;
        std::cout << "1) CLIENTE CADASTRADO :\n" ;
        std::cout << "2) NOVO CLIENTE :\n" ;
        int option ;
        std::cout << "DIGITE UMA OPCAO :\n" ;
        std::cin >> option ;
        if(option == 2){
            registerCustomerScreen(agency);
        }

        if(option == 1){
            std::cout << "\nDIGITE O CPF/CNPJ :\n" ;
            std::string document ;
            std::getline(std::cin , document);
            Person* currentCustumer = agency.getCustomer(document);
 
            std::cout << agency.listCars(true) << "\n";
            std::string plate ;
            std::cout << "\nDIGITE A PLACA DO CARRO : \n" ;
            std::getline(std::cin , plate);
            Car* currentCar = agency.getCarByPlate(plate);
            
            int totalDays ;
            std::cout << "TOTAL DE DIAS QUE O CLIENTE FICARA COM O CARRO : \n" ;
            std::cin >> totalDays ;
            
            int day , month, year ;
            std::cout << "DIA ATUAL :\n";
            std::cin >> day ;
            std::cout << "MES ATUAL :\n";
            std::cin >> month ;
            std::cout << "ANO ATUAL :\n";
            std::cin >> year ;
            Date currentDate{day , month , year} ;
            int dayR , monthR, yearR ;
            std::cout << "DIA DE RETORNO :\n";
            std::cin >> dayR ;
            std::cout << "MES DE RETORNO :\n";
            std::cin >> monthR ;
            std::cout << "ANO DE RETORNO :\n";
            std::cin >> yearR ;
            
            Date returnDate{dayR , monthR , yearR};
            
            std::cout << "INFORME O VALOR DA DIARIA : \n" ;
             double dailyRate ;
            std::cin >> dailyRate ;

            RentRegister * newReg = new RentRegister{currentCustumer,currentCar,returnDate,currentDate,dailyRate,true};

            std::cout << newReg->getRentedCar()->getObservations() << "\n";

            agency.registerReg(newReg);
            break;
       }
    }
    
}


void registerCustomerScreen(Agency &agency){
    std::cout << std::format("{:-^30}\n","CADASTRAR CLIENTE ") ; 
    
    std::cout << "NOME : \n" ;
    std::string name;
    std::getline(std::cin , name);  
    
    std::cout  << "ENDERECO :\n" ;
    std::string adress ;
    std::getline(std::cin , adress);
    
    std::cout  << "TELEFONE :\n" ;
    std::string phone ;
    std::getline(std::cin , phone);

    while (true)
    {
        
        int option ;
        std::cout << "1)PESSOA FISICA :\n2)PESSOA JURIDICA :\n";
        std::cin >> option ;
        if(option == 1){
            std::string cpf ;
            std::cout << "DIGITE O CPF :\n";
            std::getline(std::cin , cpf);

            int relation ;
            std::cout << "NIVEL DE REALCIONAMENTO : " ;
            std::cin >> relation ;
            NaturalPerson * currentCustomer = new NaturalPerson{name , phone , adress , cpf , relation};
            agency.registerCustomer(currentCustomer);
            break;
        }
        
        if(option == 2){
            std::string cnpj ;
            std::cout << "DIGITE O CNPJ :\n";
            std::getline(std::cin , cnpj);

            int relation ;
            std::cout << "NIVEL DE REALCIONAMENTO : " ;
            std::cin >> relation ;
            LegalPerson * currentCustomer = new LegalPerson{name , phone , adress , cnpj , relation};
            agency.registerCustomer(currentCustomer);
            break; 
        }

    }
    
}