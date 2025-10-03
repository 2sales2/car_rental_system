#ifndef INTERFACESCREENS_H
#define INTERFACESCREENS_H

#include "Agency.h" // Se Agency é usado nessas funções
#include <format>
// ... outras declarações de função ...
void registerCarScreen(Agency &agency);
void registerCustomerScreen(Agency& agency); // <-- ESSA LINHA É CRUCIAL
void rentCarScreen(Agency& agency);
void makePaymentScreen(Agency& agency);
void reportsScreen(Agency& agency);
// ...

#endif // INTERFACESCREENS_H