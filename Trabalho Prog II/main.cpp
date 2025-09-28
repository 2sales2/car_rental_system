#include "Car.h"
#include "Date.h"
#include "RentRegister.h"
#include "Agency.h"

int main() {

    Car carro;
    
    LegalPerson pessoa{"Dudu","Rua A","66 998823452","56789012345678",2};
    Car c{"LLL3L33",2020,"4 RODAS", 2000.0, true,"Tem 2 portas", 100.0};

    Date data_obtencao{23,02,2025};
    Date data_devolucao{7,3,2025};

    RentRegister registro{&pessoa,c,data_devolucao,data_obtencao,500.0,false,100.0,0.01};

    std::cout << registro.toString();
}

