#ifndef INTERFACESCREENS_H
#define INTERFACESCREENS_H

#include "Agency.h" // Se Agency é usado nessas funções
#include <format>
// ... outras declarações de função ...

void registerCustomerScreen(Agency& agency); // <-- ESSA LINHA É CRUCIAL
void rentCarScreen(Agency& agency);
// ...

#endif // INTERFACESCREENS_H