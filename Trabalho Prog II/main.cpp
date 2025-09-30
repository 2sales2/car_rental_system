#include "Agency.h"

int main() {

    Agency locadora;

    auto pessoa_smart_ptr = std::make_shared<LegalPerson>(
        "Dudu", 
        "Rua A", 
        "66 998823452", 
        "56789012345678", // CNPJ ou outro ID
        2 // Nível
    );
    

    locadora.registerClient(pessoa_smart_ptr);

}


