#include "Agency.h"

//adiciona carro a lista / adicionarno arquivo
void Agency::registerCar(const Car newCar){
    carsList.push_back(newCar);
}

// Adiciona um clienta na lista de clientes
void Agency::registerClient(Person* new_client) {
    clients.push_back(new_client);
}

std::vector<Car> Agency::getCarsList(){
    return carsList ;
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


int main() {

    Agency a;
    Car c{"LLL3L33",2020,"4 RODAS", 2000.0, true,"Tem 2 portas", 100.0};
    a.registerCar(c);

    Car* found_car = a.get_car_by_model("4 RODAS");
    std::cout << found_car->getPlate() << "\n";
}
