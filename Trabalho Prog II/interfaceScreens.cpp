#include "interfaceScreens.h"

void rentCarScreen(Agency &agency){
    
    while (true) {
        std::cout << std::format("{:-^30}\n","ALUGAR CARRO") ;
        std::cout << "1) CLIENTE CADASTRADO.\n" ;
        std::cout << "2) NOVO CLIENTE.\n" ;
        std::cout << "0) VOLTAR.\n";

        int option ;
        std::cout << "\nOPCAO: " ;
        std::cin >> option ;

        // Limpa buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (option == 2){
            registerCustomerScreen(agency);
        }

        else if(option == 1){
            std::cout << "\nDIGITE O CPF/CNPJ: " ;

            // Cliente informa documento e faz busca no sistema
            std::string document ;
            std::getline(std::cin , document);
            Person* currentCustumer = agency.getCustomer(document);

            // Verifica se encontram o cliente
            if (currentCustumer == nullptr) {
                std::cout << "\nERRO: Cliente não encontrado ou documento inválido.\n";
                break;
            }

            // Verifica se o cliente está envididado
            if (agency.hasPendingDebt(currentCustumer)) {
                std::cout << "\n--- ALUGUEL NEGADO ---\n";
                 std::cout << "O cliente " << currentCustumer->getName() << " possui dívidas pendentes no histórico.\n";
                 break; 
            }

            // Se não estiver, lista os carros
            std::cout << agency.listCars(true) << "\n";
            std::string plate ;
            std::cout << "\nDIGITE A PLACA DO CARRO: " ;
            std::getline(std::cin , plate);

            Car* currentCar = agency.getCarByPlate(plate);

            if (currentCar == nullptr) {
                std::cout << "\nERRO: Placa de carro inválida.\n";
                break;
            }
            
            // Verifica quantos dias o cliente vai ficar com o carro
            int totalDays ;
            std::cout << "TOTAL DE DIAS QUE O CLIENTE FICARA COM O CARRO: " ;
            std::cin >> totalDays ;
            
            int day , month, year ;
            std::cout << "DIA ATUAL: ";
            std::cin >> day ;
            std::cout << "MES ATUAL: ";
            std::cin >> month ;
            std::cout << "ANO ATUAL: ";
            std::cin >> year ;

            Date currentDate{day , month , year} ;

            int dayR , monthR, yearR ;
            std::cout << "DIA DE RETORNO: ";
            std::cin >> dayR ;
            std::cout << "MES DE RETORNO: ";
            std::cin >> monthR ;
            std::cout << "ANO DE RETORNO: ";
            std::cin >> yearR ;
            
            Date returnDate{dayR , monthR , yearR};
            
            // Verifica se o intervalo das datas é válido
            if ((Date::days_diferrence(returnDate,currentDate)) < 0) {
                std::cout << "\nERRO: Datas inválidas.\n";
                break;
            }  

            // Cria novo registro de aluguél
            RentRegister* newReg = new RentRegister{currentCustumer,currentCar,returnDate,currentDate,currentCar->getPrice()};

            // Que foi alugado passa a ficar indisponível
            currentCar->setAvailability(false);

            // Imprime os dados do registro
            std::cout << "\n" << newReg->toString() << "\n";

            // Registro é armazenado no vector de registros
            agency.registerReg(newReg);
            break;
       }
    }
    
}


void registerCustomerScreen(Agency &agency){

    std::cout << std::format("{:-^30}\n","CADASTRAR CLIENTE ") ; 

    std::cout << "NOME: " ;
    std::string name;
    std::getline(std::cin , name);  
    
    std::cout  << "ENDERECO: " ;
    std::string adress ;
    std::getline(std::cin , adress);
    
    std::cout  << "TELEFONE: " ;
    std::string phone ;
    std::getline(std::cin , phone);

    while (true)
    {
        
        int option ;
        std::cout << "\n1)PESSOA FISICA.\n2)PESSOA JURIDICA.\n";
        std::cout << "OPÇÃO: ";
        std::cin >> option ;

        // Limpa o buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(option == 1){

            std::string cpf ;
            std::cout << "\nDIGITE O CPF: ";
            std::getline(std::cin , cpf);

            int relation ;
            std::cout << "NIVEL DE REALCIONAMENTO: " ;
            std::cin >> relation ;
            NaturalPerson* currentCustomer = new NaturalPerson{name , phone , adress , cpf , relation};
            agency.registerCustomer(currentCustomer);
            break;
        }
        
        if(option == 2){

            std::string cnpj ;
            std::cout << "\nDIGITE O CNPJ: ";
            std::getline(std::cin , cnpj);

            int relation ;
            std::cout << "\nNIVEL DE REALCIONAMENTO: " ;
            std::cin >> relation ;

            LegalPerson * currentCustomer = new LegalPerson{name , phone , adress , cnpj , relation};
            agency.registerCustomer(currentCustomer);
            break; 
        }

    }
    
}

void registerCarScreen(Agency &agency) {

    std::cout << std::format("{:-^30}\n","CADASTRAR CARRO") ; 

    std::string plate;
    std::cout << "PLACA: ";
    std::cin >> plate;

    int year;
    std::cout << "ANO: ";
    std::cin >> year;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string model;
    std::cout << "MODELO: ";
    std::getline(std::cin,model);

    int mileage;
    std::cout << "KILOMETRAGEM: ";
    std::cin >> mileage;

    bool availability;
    std::cout << "\n1) DISPONÍVEL\n2)INDISPONIVEL\n";

    int option;
    std::cout << "OPÇÃO: ";
    std::cin >> option;

    if (option == 1) {
        availability = true;
    }

    else {
        availability = false;
    }

    double price;
    std::cout << "VALOR DA DIÁRIA (BASE): ";
    std::cin >> price;

    //Limpa buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string observations;
    std::cout << "OBSERVAÇÕES: ";
    std::getline(std::cin,observations);

    // Cria um novo carro
    Car* new_car = new Car{plate,year,model,mileage,availability,observations,price};

    // Novo carro é armazenado dentro de um vector
    agency.registerCar(new_car);
}

void makePaymentScreen(Agency& agency) {
    
    std::cout << std::format("{:-^30}\n", "REALIZAR PAGAMENTO");

    int id;
    std::cout << "ID DO REGISTRO: ";
    std:: cin >> id;

    RentRegister* client_register = agency.getRegisterById(id);

    // Verificação para caso não encontre o registro
    if (client_register == nullptr) {
        std::cout << "\nERRO: Registro com ID " << id << " não encontrado.\n";
        return;
    }

    // Verifca se o registro já está pago
    if (client_register->isPaid() == true) {
        std::cout << "\nAVISO: Este registro já está finalizado e pago.\n";
        return;
    }

    // Visualizar o registro
    std::cout << "\n" << std::format("{:=^40}\n", " DADOS DO REGISTRO ") << "\n";
    std::cout << client_register->toString();

    // Se o carro ainda está associado ao cliente
    if (client_register->getRentedCar()->getAvailability() == false) {

        // Processo de Devolução
        std::cout << "\n" << std::format("{:=^40}\n", " PROCESSO DE DEVOLUÇÃO ") << "\n";

        int new_km;
        std::cout << "DIGITE A KILOMETRAGEM ATUAL DO CARRO: ";
        std::cin >> new_km;

        // Limpar buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        double final_value = agency.getRegisterById(id)->calculate_rentValue();
        std::cout << "\n-> VALOR TOTAL: R$ " << final_value << "\n";

        int payment_method;
        std::cout << "\nSELECIONE A FORMA DE PAGAMENTO:\n";
        std::cout << "1) Dinheiro\n2) Cartão de Crédito/Débito\n3) Pix\n";
        std::cout << "OPÇÃO: ";
        std::cin >> payment_method; 
        
        // Limpar buffer 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        double amount_paid;
        std::cout << "VALOR PAGO PELO CLIENTE: R$ ";
        std::cin >> amount_paid; 

        // Limpar buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n--- PROCESSANDO DEVOLUÇÃO E PAGAMENTO... ---\n";
        
        // Realização do pagamento
        std::string result = Payments::process_payment(client_register,amount_paid,new_km);
        std::cout << result << "\n";
    }

    else {
        // Se cliente está endividado
        std::cout << "\n" << std::format("{:=^40}\n", " PAGAMENTO DE DÍVIDA PENDENTE ") << "\n";
        
        // Exibir o saldo devedor
        std::cout << "DÍVIDA ATUALMENTE REGISTRADA: R$ " << client_register->getTotalDebt() << "\n";
        
        int payment_method;
        std::cout << "\nSELECIONE A FORMA DE PAGAMENTO:\n";
        std::cout << "1) Dinheiro\n2) Cartão de Crédito/Débito\n3) Pix\n";
        std::cout << "OPÇÃO: ";
        std::cin >> payment_method; 
        
        // Limpar buffer 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        double amount_paid;
        std::cout << "VALOR PAGO PELO CLIENTE: R$ ";
        std::cin >> amount_paid; 
        
        // Limpar buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string result = Payments::process_debt_payment(client_register, amount_paid);

        std::cout << result << "\n";
    }

}

void reportsScreen(Agency& agency) {

    while (true) {
        std::cout << std::format("{:-^30}\n", " RELATÓRIOS DA LOCADORA ");
        std::cout << "1) CARROS ALUGADOS POR PERÍODO.\n";
        std::cout << "2) FATURAMENTO POR PERÍODO\n";
        std::cout << "3) CLIENTES COM DÍVIDA PENDENTE\n";
        std::cout << "4) DADOS DE UM CLIENTE ESPECÍFICO\n";
        std::cout << "0) VOLTAR\n";

        int option;
        std::cout << "\nOPÇÃO: ";
        std::cin >> option;
        
        // Limpa buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (option == 0) {
            break; 
        }

        if (option == 1 || option == 2) {
            int day, month, year;

            std::cout << "\n--- PERÍODO DE INÍCIO ---\n";
            std::cout << "DIA: ";
            std::cin >> day;
            std::cout << "MÊS: ";
            std::cin >> month;
            std::cout << "ANO: ";
            std::cin >> year;

            Date start_date{day,month,year};
            
            // Limpa buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

            std::cout << "\n--- PERÍODO FINAL ---\n";
            std::cout << "DIA: ";
            std::cin >> day;
            std::cout << "MÊS: ";
            std::cin >> month;
            std::cout << "ANO: ";
            std::cin >> year;
            
            Date end_date{day, month, year};

            // Limpa buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

            if (option == 1) {
                // Relatório de carros por período
                std::cout << agency.reportCarsRented(start_date, end_date) << "\n";

            } 
            
            else {
                // Faturamento por período
                std::cout << agency.billingReport(start_date, end_date) << "\n";
            }

        }

        else if (option == 3) {
            // Clientes com dívida
            std::cout << "\n" << std::format("{:-^30}\n", " CLIENTES COM DÍVIDA ") << "\n";
            std::cout << agency.reportIndebtCustomers() << "\n";
        }

        else if (option == 4) {
            // Relatório de dados de cliente específico.
            std::string document;
            std::cout << "\nDIGITE O CPF/CNPJ DO CLIENTE: ";
            
            std::getline(std::cin, document);
            
            std::cout << agency.reportCustomerInf(document) << "\n";
            
        }
    }
}