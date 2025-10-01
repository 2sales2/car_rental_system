#include "Agency.h"

//metodos para adicionar dados as listas
void Agency::registerCar(Car *newCar){
    if(newCar){    
        carsList.push_back(newCar);
    }
}

void Agency::registerCustomer(Person *newCustomer){
    if(newCustomer){
        customers.push_back(newCustomer);
    }
}

void Agency::registerReg(RentRegister *newReg){
    if(newReg){
        registerList.push_back(newReg);
    }
}


// Função que obtém um carro pela placa
Car* Agency::getCarByPlate(const std::string plate) {

    if (carsList.empty()) {
        return nullptr;
    }

    for(Car* currentCar : carsList) {

        // Busca um carro na lista de carros
        if(currentCar->getPlate() == plate) {
            return currentCar;
        }

    }
    // Se não encontrou
    return nullptr;

}



// Função que obtem o carro pelo modelo
Car* Agency::getCarByModel(const std::string model) {

    // Busca um carro na lista de carros
    if (carsList.empty()) {
        return nullptr;
    }

    for (Car* currentCar : carsList) {
        
        if (currentCar->getModel() == model) {
            return currentCar;
        }
    }

    return nullptr;

}

RentRegister* Agency::getRegisterById(int searched_id) {

    //Verifica se o vector de registros está vazio
    if (registerList.empty()) {
        return nullptr;
    }

    else {
        // Retorna ponteiro para registro
        for (RentRegister* currentReg : registerList) {
            if (currentReg->getRegisterID() == searched_id) {

                return currentReg;
            }
        }
    }


    return nullptr;
}

Person* Agency::getCustomer(const std::string document){
    for(Person* currentPerson : customers){
        if(currentPerson->matchesIdentifier(document)){
            return currentPerson ;
        }
    }

    return nullptr ;
}


std::string Agency::reportCarsRented(const Date startPeriod , const Date endPeriod){
    int count{0} ;
    std::string output{"RELATORIO DE CARROS ALUGADOS:\n"} ;
    output += "INICIO : " +startPeriod.toString() + "\n" +
              "FIM : " +endPeriod.toString() + "\n\n";  

    for(RentRegister * currentReg : registerList){
        if(Date::isWhithinPeriod(currentReg->getRentDate() ,startPeriod , endPeriod )){
            output += "--------------------------\n";            
            output += currentReg->getRentedCar()->toString() +"\n\n";
            count++ ;
        }
    }
    output += "--------------------------\n";
    output += "TOTAL : " + std::to_string(count) + "\n" ;
    
    return output ;
}

//relatorio de faturamento
std::string Agency::billingReport(const Date startPeriod , const Date endPeriod){
    
    std::string output{"RELATORIO DE FATURAMENTO:\n"};
    output += "INICIO : " + startPeriod.toString() + "\n" +
              "FIM : " + endPeriod.toString() + "\n" ; 
    double total {0.0} ;
    int total_reg{0} ;
    for(RentRegister * currentReg : registerList){
        if(Date::isWhithinPeriod(currentReg->getRentDate() , startPeriod , endPeriod) && currentReg->isPaid() == true){
            output += "--------------------------\n";
            output += currentReg->toString();
            total += currentReg->getRentValue() ;
            total_reg++;
        }
    }

    output += "\n--------------------------\n";
    output+= "TOTAL DE REGISTROS : " + std::to_string(total_reg) + "\n" + 
             "TOTAL : " + std::to_string(total) + "\n";

    return output ;
}

std::string Agency::listCars(bool available){
    
    std::string output{"CARROS : \n\n"};
    int count{0};
    for(Car * currentCar : carsList){

        if(available)
        {
            if(currentCar->getAvailability() == true){
            output += "--------------------------\n";
            output += currentCar->toString() ;
            count++;}
        }
        else{

            output += "--------------------------\n";
            output += currentCar->toString() ;
            count++;
        }

    }
    output += "\n--------------------------\n";
    output += "TOTAL : " + std::to_string(count) ;

    return output ;
}

std::string Agency::reportIndebtCustomers(){
    int count{0};
    double total{0.0};
    std::string output{"RELATORIO DE CLIENTES ENDIVIDADOS :\n\n"};
    for(RentRegister * currentReg : registerList){
        if(currentReg->isPaid() == false){
            output += "--------------------------\n";
            output += currentReg->getTenant()->toString() + "\n" +
                      currentReg->getRentedCar()->toString() + "\n" +                      
                      "\nVALOR A PAGAR : " + std::to_string(currentReg->getRentValue()) + "\n" ;
            count++;
            total += currentReg->getTotalDebt();
        }
    }
    output += "--------------------------\n";
    output += "\nQUANTIDADE : " + std::to_string(count) +"\n"+
              "TOTAL : " + std::to_string(total) + "\n" ;
    return output ;

}

std::string Agency::reportCustomerInf(const std::string document){
    Person * currentPerson = getCustomer(document);
    return currentPerson->toString();
}
