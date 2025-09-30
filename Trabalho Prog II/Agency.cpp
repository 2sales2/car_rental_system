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

RentRegister* Agency::get_register_by_id(int searched_id) {

    //Verifica se o vector de registros está vazio
    if (registerList.empty()) {
        return nullptr;
    }

    else {
        // Retorna ponteiro para registro
        for (int i{0}; i < registerList.size(); i++) {
            if (searched_id == registerList.at(i)->getRegisterID()) {

                return registerList.at(i);
            }
        }
    }


    return nullptr;
}




int main() {


}
    
