#include "Agency.h"



void Agency::registerCar(const Car &newCar){
    carsList.push_back(newCar);
}

// Adiciona um clienta na lista de clientes
void Agency::registerClient(std::shared_ptr<Person> newClient) {
    if(newClient){
        clients.push_back(newClient);
    }
}


// Função que obtém um carro pela placa
Car* Agency::get_car_by_plate(std::string plate) {

    if (carsList.empty()) {
        return nullptr;
    }

    for (int i{0}; i < carsList.size(); i++) {

        // Busca um carro na lista de carros
        if (carsList.at(i).getPlate() == plate) {
            return &carsList.at(i);
        }

    }
    // Se não encontrou
    return nullptr;

}

// Função que obtem o carro pelo modelo
Car* Agency::get_car_by_model(std::string model) {

    // Busca um carro na lista de carros
    if (carsList.empty()) {
        return nullptr;
    }

    for (int i{0}; i < carsList.size(); i++) {
        
        if (carsList.at(i).getModel() == model) {
            return &carsList.at(i);
        }
    }

    return nullptr;

}


std::string Agency::reportCarsRented(Date startPeriod , Date endPeriod){
    int count {0};

    std::string output {"RELATORIO DE CARROS ALUGADOS POR PERIODO \n"};
    output += "INICIO : " + startPeriod.toString() + "\n" + 
              "FIM : " + endPeriod.toString() ; 


    for(RentRegister currentRegister: registerList){
                
        if(startPeriod.getYear() <= currentRegister.getRentDate().getYear() && 
           endPeriod.getYear()  >= currentRegister.getRentDate().getYear() ){
            
            if(startPeriod.getMonth() <= currentRegister.getRentDate().getMonth() &&
                endPeriod.getMonth() >= currentRegister.getRentDate().getMonth() ){

                    if(startPeriod.getDay() <= currentRegister.getRentDate().getDay() &&
                       startPeriod.getDay() >= currentRegister.getRentDate().getDay()){
                            output +=  "\n" + currentRegister.getRentedCar().toString() + "\n" ;
                            count++;
                       }
                }
           }
    }

    output += "TOTAL : "+ std::to_string(count) + "\n";

    return output ;
}


int main() {


}
    
